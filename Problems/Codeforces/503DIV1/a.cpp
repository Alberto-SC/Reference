#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,x,c,m;
    while(t--){
        cin>>n>>m;
        vector<vector<pair<int,int>>> p(m);
        vector<pair<int,int>> _all;
        for(int i = 0;i<n;i++){
            cin>>x>>c;
            x--;
            p[x].push_back({c,i});
            if(x)
                _all.push_back({c,i});
            else 
                _all.push_back({1e15,i});
        }
        sort(_all.begin(),_all.end());
        for(int i =0;i<m;i++)
            sort(p[i].begin(),p[i].end());
        vector<bool> used(n);
        int ans = 1e16;
        for(int i = 1;i<=n;i++){
            int votes = p[0].size();
            int res = 0;
            if(votes>i)continue;
            used.assign(n,false);
            for(int j = 1;j<m;j++){
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
            for(int j = 0;j<n;j++){
                if(votes ==i)break;
                if(!used[_all[j].second]){
                    votes++;
                    res+=_all[j].first;
                }
            }
            ans = min(ans,res);
        }
        cout<<ans<<endl;
    }
}     