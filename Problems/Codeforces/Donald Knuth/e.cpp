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


    double l = 0,r = *max_element(B.begin(),B.end());

    int cont = 20;
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