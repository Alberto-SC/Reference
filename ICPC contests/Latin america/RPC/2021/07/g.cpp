#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        string s,t;
        map<string,int> mp; 
        vector<string> ans(n);
        for(int i = 1;i<=n;i++){
            mp["T"+to_string(i)] = i-1;
            ans[i-1]= "T"+to_string(i);
        }
        for(int i = 0;i<m;i++){
            cin>>s>>t;
            if(mp[s]>mp[t]){
                for(int j = mp[t]+1;j<=mp[s];j++){
                    mp[ans[j]]--;
                }
                mp[t] = mp[s]+1;
            }
            for(auto c:mp){
                ans[c.second] = c.first;
            }
        }
        for(int i = 0;i<n;i++){
            if(i!=n-1)
                cout<<ans[i]<<" ";
            else 
                cout<<ans[i];
        }
        cout<<endl;    
    }
    return 0;
}  
