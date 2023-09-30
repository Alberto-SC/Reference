#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);

using comp = complex<long double>;
#define print(A) for(auto c: A )cout<<c<<" ";
#define printc(A) for(comp c: A )cout<< c.real()<<" ";
#define printM(A)for(auto c: A){printc(c);cout<<endl;}
typedef vector<comp> vec;
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

int lesspow(int n){
    int ans = 1;
    while(ans<n)ans<<=1;
    return ans;
}
void mult(vec &A, vec &B){
    int n = A.size()+B.size()-1;
    int n0= lesspow(n);
    A.resize(n0);
    B.resize(n0);
    fft(A,1);
    fft(B,1);
    for(int i = 0;i<n0;i++){
        A[i]*=B[i];
    }
    fft(A,-1);
    A.resize(n);
}

int main(){
    string ADN, B;
    cin>>ADN>>B;
    int n1 = ADN.size(),n2 = B.size();
    reverse(B.begin(),B.end());

    vector<char> alpha = {'A', 'C', 'G', 'T'};
	vector<int> ans(n1+n2-1);
	for(char c : alpha){
		vector<comp> a(n1), b(n2);
		for(int i = 0; i < n1; ++i){
			if(ADN[i] == c) a[i] = 1.0;
		}
		for(int i = 0; i < n2; ++i){
			if(B[i] == c) b[i] = 1.0;
		}
        //print(a)cout<<"\n";
        //print(b)cout<<"\n";
		mult(a,b);
        //print(a)cout<<endl;
		for(int i = n2 - 1; i < n1; ++i){
			ans[i] += round(a[i].real());
		}
	}
    
    //print(ans)cout<<"\n";
    int an = 1<<30;
    for(int i = n2-1;i<n1;i++){    
       an = min(an,n2-ans[i]);
    }
    cout<<an<<endl;
    return 0;
}