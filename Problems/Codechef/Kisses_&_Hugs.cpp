#include<iostream>
using namespace std;
const m = 1000000007;
long long int exp(long long a,long long b,long long m){
	long long int ans = 1;
	while(b){
		if(b&1){
			ans*=a;
			ans%=m;
		}
		b>>=1;
		a*=a;
		a%=m;
	}
	return ans;
}
int main(){
	long long int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<exp(n,2,m)-exp(1,2,m);
	}
	return 0;
}