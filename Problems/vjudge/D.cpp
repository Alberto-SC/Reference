#include <iostream>
using namespace std;
const long long int mod=1e9+7;
long long  int pw(long long int a,long long int b){
	long long p =1;
	while(b){
		if(b&1) p = p *a %mod;
		b>>=1;
		a = a * a%mod;
	}
	return p ;
}
int main(){
	long long int n,m,k;
	cin>>n>>m>>k;
	if((n%2)!=(m%2)  &&  k==-1) cout<<0<<endl;
	else cout<<pw (pw(2,n-1), m-1) <<endl;
	
	return 0;
} 