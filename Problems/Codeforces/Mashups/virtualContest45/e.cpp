#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n;
        vector<pair<int,pair<int,int>>> g(n);
        for(int i  = 0;i<n;i++){
            cin>>g[i].second.first>>g[i].first;
            g[i].second.second= i+1;
        }
        sort(g.begin(),g.end(),[&](pair<int,pair<int,int>>a,pair<int,pair<int,int>> b){
            return a.first>b.first;
        });
        cin>>k;
        vector<pair<int,int>> tables(k);
        for(int i = 0;i<k;i++){
            cin>>tables[i].first;
            tables[i].second= i+1;
        }
        sort(tables.begin(),tables.end());
        vector<bool> used(k);
        int ans = 0;
        vector<pair<int,int>> res;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<k;j++){
                if(tables[j].first>=g[i].second.first&&!used[j]){
                    ans+=g[i].first;
                    used[j] = true;
                    res.push_back({g[i].second.second,tables[j].second});
                    break;
                }
            }
        }
        cout<<res.size()<<" "<<ans<<endl;
        for(auto c:res)cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}  
