#include<bits/stdc++.h> 
using namespace std; 
const long long p = 50, mod = 1e9+9;
int main(){
    string s;
	cin>>s;
	int n = s.size();
	vector<long long> pows(s.size() + 1), hash(s.size() + 1);
	hash[0] = 0;
	pows[0] = 1;
	for(int i = 0; i < n; ++i) {
		pows[i + 1] = pows[i] * p % mod;
		hash[i + 1] = (hash[i] + pows[i] * s[i]) % mod;
	}
	int ans = 0;
	int l = 0, r = n;
    // for(auto c:hash)cout<<c<<" ";
    // cout<<endl;
	for(int i = 1; i <= n - i; ++i) {
		if((mod + hash[i] - hash[l]) * pows[r - i] % mod == (mod + hash[r] - hash[n - i]) % mod) {
			ans += 2;
			l = i;
			r = n - i;
		}
	}
	if(l < r) ++ans;
	cout<<ans<<endl;
} 