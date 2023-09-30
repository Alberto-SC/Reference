#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,x,c,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<pair<int,int>> p(n,m);
        vector<int> _all;
        for(int i = 0;i<n;i++){
            cin>>x>>c;
            x--;
            p[x].push_back({c,i});
            if(x)
                _all.push_back(c);
            else 
                _all.push_back(1e15);
        }
        sort(_all.begin(),_all.end());
        for(int i =0;i<m;i++)
            sort(p[i].begin(),p[i].end());
        vector<bool> used(n);
        int ans = 1e16;
        for(int i = 0;i<=n;i++){
            int votes = p[0];
            int res = 0;
            used.assign(n,false);
            for(int j = 1;j<n;j++){
                if(p[j].size()>=i){
                    int need = (p[j].size()-i)+1;
                    for(int k = 0;k<need;k++){
                        votes++;
                        res+=p[j][k].first;
                        used[p[j][k].second] = true;
                    }
                }
            }
            if(votes>i)continue;
            for(int i = 0;i<n;j++){
                if(!used[i]){
                    votes++;
                    res+=_all[i];
                }
                if(votes ==i)break;

            }
            ans = min(ans,res);
        }
        cout<<ans<<endl;
    }
}     