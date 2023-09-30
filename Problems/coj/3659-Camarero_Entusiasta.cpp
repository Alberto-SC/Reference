#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0); 
	int t,n;
	cin>>t;
	unsigned long long ans ;
	for(int j = 0;j<t;j++){
		cin>>n;
		ans = 1;
		for(int i = 2;i<=n;i++)
			ans *= i;
		cout<<ans<<endl;
	}
	return 0;

}