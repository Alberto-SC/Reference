#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
using comp = complex<long double>;
#define print(A) for(auto c:A)cout<<c<<" ";
#define printc(A) for(comp c: A)cout<<c.real()<<" ";
#define printm(A) for(auto c:A){print(c)cout<<endl;}

typedef vector<comp> vec;

bool isZero(comp z){
	return abs(z.real()) < 1e-2;
}

int lesspow(int a){
    int ans = 1;
    while(ans<a)ans<<=1;
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

void mult(vec &a, vec&b){
    int n0= a.size()+b.size()-1;
    int n = lesspow(n0);
    a.resize(n);
    b.resize(n);
    fft(a,1);
    fft(b,1);
    for(int i = 0;i<n;i++)
        a[i] *= b[i];
    fft(a,-1);
    a.resize(n0);
    

}

int main(){
    int n,a,m,an;
    while(cin>>n){
        vector<int> pol;
        int ma = -100;
        an = 0;
        for(int i = 0;i<n;i++){
            cin>>a;
            ma = max(ma,a);
            pol.push_back(a);
        }
        //print(pol)cout<<endl;
        vec po(ma+1);
        po[0] = 1;
        for(int i = 0;i<n;i++)
            po[pol[i]] = 1.0;
        
        //print(po)cout<<endl;
        vec copy;
        copy = po;
        //reverse(copy.begin(),copy.end());
        mult(po,copy);
        //printc(po)cout<<endl;
        cin>>m;
        //cout<<po.size()<<endl;
        for(int i = 0;i<m;i++){
            cin>>a;
            if(a<po.size()&& !isZero(po[a]))an++;
        }
        cout<<an<<endl;
    }
    return 0;
}