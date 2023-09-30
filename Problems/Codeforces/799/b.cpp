#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        if((n-mp.size())%2==0)cout<<mp.size()<<endl;
        else cout<<mp.size()-1<<endl;
    }
    return 0;
} 