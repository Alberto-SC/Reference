#include <iostream>
#include <vector>
using namespace std;
typedef int ull;
int sieve(ull n,vector<ull> & divs){
	divs.resize(n+1,0);
	for(ull i = 1;i<=n;i++){
		for(ull j = i;j<=n;j+=i){
			divs[j]++;
		}
	}
}
int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0);  
	ull a,limit = 1100000,ans;
	cin>>a;
	ull s = a+1,i = a-1;
	vector<ull> divs;
	sieve(limit+1,divs);


	while(1){
		if(s <= limit && divs[s] == divs[a]){
			ans = s; break;}
		if(i > 0 && divs[i] == divs[a]){
			ans = i ;break;}
		s++;
		i--;
	}
    cout<<ans<<endl;
	return 0;
}

