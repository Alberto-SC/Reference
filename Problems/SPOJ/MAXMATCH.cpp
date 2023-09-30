 #include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L); 
using comp = complex<long double>;
using lli = long long int;
typedef vector<comp> vec;
#define print(A) for(auto c: A )cout<< c<<" ";
#define printc(A) for(comp c: A )cout<< c.real()<<" ";
#define printM(A)for(auto c: A){printc(c);cout<<endl;}
vec alp[3];

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
    string a;
    cin>>a;
    int n = a.size();
    alp[0].resize(n);
    alp[1].resize(n);
    alp[2].resize(n);
    for(int i = 0;i<n;i++){
        alp[a[i]-'a'][i]= 1.0;
        
    }
    //cout<<"hfge";
    //printM(alp);
    for(int i = 0;i<3;i++){
        vec org;
        org = alp[i];
        reverse(alp[i].begin() , alp[i].end());
        mult(alp[i],org);
    }  
    int  max = -10000,match,sol;
    vector<int> ans(n-1);
    for(int i = n;i<n+n-1;i++){
        ans[i-n] =  round(alp[0][i].real()) + round(alp[1][i].real()) + round(alp[2][i].real());
        if(ans[i-n] >= max){
            max = ans[i-n];
            sol = i;
        }
    }
    //printM(alp);
    cout<<max<<endl;
    for(int i = 0;i<n;i++){
        if(ans[i] == max)cout<<i+1<<" ";
    }
    return 0;
}