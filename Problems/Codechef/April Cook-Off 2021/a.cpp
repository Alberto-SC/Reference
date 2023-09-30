#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> nums(n);
        map<int,int>mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        vector<int> z;
        for(auto c:mp)
            z.push_back(c.second);    
        sort(z.rbegin(),z.rend());
        for(int i = 0;i<z.size();i++)
            x -=min(x,z[i]-1);
        
        while(x){
            z.pop_back();
            x--;
        }
        cout<<z.size()<<endl;
    }
    return 0;
}  
