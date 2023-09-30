#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double ld;
int main(){
    lli n,h;
    cin>>n>>h;
	cout<<fixed<<setprecision(10);
    for(int i=1;i<=n-1;i++){
		cout<<sqrt(ld(i)/ld(n))*ld(h);
		if(i<n-1) cout<<" ";
	}	
	cout<<endl;
    return 0;
}
