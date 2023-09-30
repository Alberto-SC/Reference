#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
vector<bool> primes(100005,true);
void criba(int n){
	primes[0] = primes[1] = false;
	for(int i = 4;i<=n;i+=2)
		primes[i] = false;
	for(int i = 3;i*i<n;i+=2){
		if(primes[i]);
			for(int j = i*i;j<=n;j+=2*i){
				primes[j] = false;
		}
	}


}
int str_int(string st){
	int n;
	stringstream ss(st);
	ss>>n;
	return n;
}
int main(){
	string a;
	criba(100000);
	while(true){
		cin>>a;
		if(a == "0") break;
		int ans = 0;
		bool y = false;
		for(int i = 5;i>=1;i--){
			if(y)break;
			for(int j = 0;j<(a.size()-i+1);j++){
				int tmp = str_int(a.substr(j,i));
				if(primes[tmp]){
					ans = max(ans,tmp);
					y = true;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;

}