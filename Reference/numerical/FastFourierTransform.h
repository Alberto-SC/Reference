/**
 * Author: Ludo Pulles, chilli, Simon Lindholm
 * Date: 2019-01-09
 * License: CC0
 * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf (do read, it's excellent)
   Accuracy bound from http://www.daemonology.net/papers/fft.pdf
 * Description: fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x / N)$ for all $k$. N must be a power of 2.
   Useful for convolution:
   \texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.
   For convolution of complex numbers or more than two vectors: FFT, multiply
   pointwise, divide by n, reverse(start+1, end), FFT back.
   Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$
   (in practice $10^{16}$; higher for random inputs).
   Otherwise, use NTT/FFTMod.
 * Time: O(N \log N) with $N = |A|+|B|$ ($\tilde 1s$ for $N=2^{22}$)
 * Status: somewhat tested
 * Details: An in-depth examination of precision for both FFT and FFTMod can be found
 * here (https://github.com/simonlindholm/fft-precision/blob/master/fft-precision.md)
 */
#pragma once

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

// 
// Get the sums of products of all subsets of size k

#include <bits/stdc++.h>

using namespace std;
const double PI = 4*atan(1);
typedef complex<double> base;
vector<base> FFT;
long long FFT_N;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

void init_fft(long long n){
    FFT_N  = n;
    FFT.resize(n);
    double angle = 2 * PI / n;
    for(int i = 0; i < n; i++)
    FFT[i] = base( cos(i * angle), sin(i * angle));
}

void fft (vector<base> & a){
    long long n = (long long) a.size();
    if (n == 1)  return;
    long long half = n >> 1;
    vector<base> even (half),  odd (half);
    for (int i=0, j=0; i<n; i+=2, ++j){
        even[j] = a[i];
        odd[j] = a[i+1];
    }
    fft (even), fft (odd);
    for (int i=0, fact = FFT_N/n; i < half; ++i){
        base twiddle =  odd[i] * FFT[i * fact] ;
        a[i] =  even[i] + twiddle;
        a[i+half] = even[i] - twiddle;
    }
}

void multiply (const vector<double> & a, const vector<double> & b, vector<double> & res){
    vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    long long n = 1;
    while (n < 2*max (a.size(), b.size()))  n <<= 1;
    fa.resize (n),  fb.resize (n);

    init_fft(n);
    fft (fa),  fft (fb);
    for (size_t i=0; i<n; ++i)
        fa[i] = conj( fa[i] * fb[i]);

    fft (fa);
    res.resize (n);
    for (size_t i=0; i<n; ++i){
      res[i] = (fa[i].real() / n );
    }
}

vector<double> getProb(double x,vector<int> &B,double d,double p){
    vector<double> P;
    for(int i = 0;i<B.size();i++){
        int b = B[i];
        double z = min(1.0,x/b);
        double y = min(1.0,d*(x/b));
        P.push_back((p*y)+((1-p)*z));
    }
    return P;
}


vector<double> getSums(vector<double> Probs){
    vector<double> inp,res;
    vector<vector<double>> calc[20];
    int n = Probs.size();
    for(int i=0;i<n;i++){
        inp.clear();
        inp.push_back(1);
        inp.push_back(Probs[i]);
        calc[0].push_back(inp);
    }
    int p = 0,l = n;
    while(l>1){
        p++;
        for(int i=0;i<l/2;i++){
            calc[p].push_back(res);
            multiply(calc[p-1][2*i],calc[p-1][2*i+1],calc[p][i]);
        }
        if(l%2)
            calc[p].push_back(calc[p-1][l-1]);
        l=calc[p].size();
    }

    return calc[p][0];
}

bool isEqual(double a,double b){
    return fabs(a-b)<1e-8;
}

int main(){__
    int n;
    double x,P,d,e;


    cin>>n;
    cin>>d>>P>>e;
    vector<int> B(n);

    for(auto &c:B)cin>>c;


    double l = 0,r = 10;

    int cont = 60;
    cout<<fixed<<setprecision(6);
    while(cont--){
        double m = (l+r)/2;

        auto Probs = getProb(m,B,d,P);

    
        int contOnes = 0;
        vector<double> P2;
        double prod = 1;
        double prodI = 1;

        for(auto &c:Probs){
            if(isEqual(c,1.0))
                contOnes++;
            else {
                P2.push_back(c/(1.0-c));
                prodI*=(1.0-c);
                prod*=c;
            }
        }

        double E = 0;
        if(contOnes== n){
            E = n;
        }
        else{
            auto sums = getSums(P2);
            for(int i = contOnes;i<n;i++){
                int need = i-contOnes;
                E+=i*(prodI*sums[need]);
            }
            E+=n*prod;
        }

        if(E>=e)r = m;
        else l = m;
    }

    cout<<r<<endl;
  return 0;
}