#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L); 
using comp = complex<long double>;
using lli = long long int;
typedef vector<comp> vec;
#define print(A)  for(auto c : A) cout << c << " ";
#define fr(i,n) for(int i = 0;i<n;i++);
#define br() cout<<"\n";
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
int main(){
	int t;
	int n,a;
	cin>>t;
	while(t--){
		cin>>n;
		vec a(n+1),b(n+1);
		for(int i = 0;i<=n;i++)
			cin>>a[i];
		
		for(int i = 0;i<=n;i++)
			cin>>b[i];
		multiply(a,b);
		for(int i = 0;i<a.size();i++)
			cout<<(long long int) round(a[i].real())<<" ";
		
		cout<<"\n";
	}
	return 0;
}