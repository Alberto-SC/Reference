#include <iostream>
using namespace std;
long long pw(long long a,long long b,long long m){
	long long ans= 1,tmp = a;
	while(b){
		if(b&1){
			ans *= tmp;
			ans %= m;
		}
		b  >>=1;
		tmp *= tmp, tmp %= m;
	}
	return ans;
}

int main(){
	long long a,b,m,t;
	cin>>t;
	while(t--){
		cin>>a>>b>>m;
		cout<<pw(a,b,m)<<endl;
	}
	return 0;
}