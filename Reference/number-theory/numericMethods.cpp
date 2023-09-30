//_________________________FFT_________________________________//
/*
	[Tested Codeforces 954I ]
*/
const double PI = acos(-1.0L);
using comp = complex<long double>;
using lli = long long int;
typedef vector<comp> vec;
#define print(A)  for(auto c : A) cout << c << " ";
#define isZero(z) abs(z.real()) < 1e-3;

int lesspow2(int n){
	int ans = 1;
	while(ans<n)ans<<=1;
	return ans;
}

void fft(vec& a, int inv){
	int n = a.size();
	for(int i = 1,j = 0;i<n-1;i++){
		for(int k = n>>1;(j^= k) <k; k>>= 1);
			if(i<j) swap(a[i],a[j]);
	}
	for(int k = 1;k<n;k<<=1){
		comp wk = polar(1.0,PI/k*inv);
		for(int i = 0;i<n;i+= k<<1){
			comp w(1);
			for(int j = 0;j<k;j++,w = w*wk){
				comp t = a[i+j+k]*w;
				a[i+j+k] = a[i+j]-t;
				a[i+j] += t;
			}
		}
	}
	if(inv == -1)
		for(int i = 0;i<n;i++)
			a[i]/=n;

}

void fft(vector<cd> &a,int invert){
	int n=a.size();
	for(int i=1,j=0;i<n;i++){
		int z=(n>>1);
		for(;(j&z);z=(z>>1)){
			j=(j^z);
		}
		j=(j^z);
		if(i<j)
		swap(a[i],a[j]);
	}
	for(int len=2;len<=n;len=(len<<1)){
		double ang=(2*PI/len)*((invert?-1:1));
		cd wlen(cos(ang),sin(ang));
		for(int i=0;i<n;i+=len){
			cd w(1);
			for(int j=0;j<len/2;j++){
				cd u=a[i+j],v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if(invert){
		for(int i=0;i<n;i++){
			a[i]/=n;
		}
	}
}

vec multiply(vec &a,vec &b){
	int n0 = a.size()+b.size()-1;
	int n = lesspow2(n0);
	a.resize(n);
	b.resize(n);
	fft(a,1);
	fft(b,1);
	for(int i = 0;i<n;i++)
		a[i]*= b[i];
	fft(a,-1);
	a.resize(n0);
	return a;
}


#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);
using lli = int64_t;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printc(A)for(auto c:A)cout<<c.real()<<" ";cout<<endl;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
int N = 2500007;
int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}
 
lli powerMod(lli b, lli e, lli m){
	lli ans = 1;
	e %= m-1;
	if(e < 0) e += m-1;
	while(e){
		if(e & 1) ans = ans * b % m;
		e >>= 1;
		b = b * b % m;
	}
	return ans;
}
 
template<int p, int g>
void ntt(vector<int> & X, int inv){
	int n = X.size();
	for(int i = 1, j = 0; i < n - 1; ++i){
		for(int k = n >> 1; (j ^= k) < k; k >>= 1);
		if(i < j) swap(X[i], X[j]);
	}
	vector<lli> wp(n>>1, 1);
	for(int k = 1; k < n; k <<= 1){
		lli wk = powerMod(g, inv * (p - 1) / (k<<1), p);
		for(int j = 1; j < k; ++j)
			wp[j] = wp[j - 1] * wk % p;
		for(int i = 0; i < n; i += k << 1){
			for(int j = 0; j < k; ++j){
				int u = X[i + j], v = X[i + j + k] * wp[j] % p;
				X[i + j] = u + v < p ? u + v : u + v - p;
				X[i + j + k] = u - v < 0 ? u - v + p : u - v;
			}
		}
	}
	if(inv == -1){
		lli nrev = powerMod(n, p - 2, p);
		for(int i = 0; i < n; ++i)
			X[i] = X[i] * nrev % p;
	}
}
 
template<int p, int g>
void mult(vector<int> &A, vector<int> &B){
	int sz = A.size() + A.size() - 1;
	int size = nearestPowerOfTwo(sz);
	A.resize(size), B.resize(size);
	ntt<p, g>(A, 1);
	for(int i = 0; i < size; i++)
		B[i] = (lli)A[i] * A[i] % p;
	ntt<p, g>(B, -1);
	B.resize(sz);
	// return A;
}