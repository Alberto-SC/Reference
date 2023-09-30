#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        for(auto &c:a)cin>>c;
        vector<int> b(n);
        for(auto &c:b)cin>>c;
        vector<vector<pair<int,int>>> v;
        v.push_back({});
        for(int i = 0;i<n;i++){
            v[0].push_back({i,i});
        }
        int ans = 0;
        for(int i = 29;i>=0;i--){
            bool flag = true;
            for(int j = 0;j<v.size();j++){
                int c0 = 0,c1 = 0;
                for(int k = 0;k<v[j].size();k++){
                    if(((a[v[j][k].first]>>i)&1)== 0)c0++;
                    if((b[v[j][k].second]>>i)&1)c1++;
                }
                if(c0!=c1)flag = false;
            }
            if(flag){
                ans|=1<<i;
                vector<vector<pair<int,int>>> nw;
                for(int j = 0;j<v.size();j++){
                    int c0 = 0,c1 = 0;
                    vector<int> az;
                    vector<int> ao;
                    vector<int> bz;
                    vector<int> bo; 
                    for(int k = 0;k<v[j].size();k++){
                        if(((a[v[j][k].first]>>i)&1)== 0)az.push_back(v[j][k].first),c0++;
                        else ao.push_back(v[j][k].first);

                        if((b[v[j][k].second]>>i)&1)bo.push_back(v[j][k].second),c1++;
                        else bz.push_back(v[j][k].second); 
                    }
                    if(c0){
                        nw.push_back({});
                        for(int k= 0;k<c0;k++){
                            nw.back().push_back({az[k],bo[k]});
                        }
                    }
                    if(v[j].size()-c0){
                        nw.push_back({});
                        for(int k= 0;k<v[j].size()-c0;k++){
                            nw.back().push_back({ao[k],bz[k]});
                        }
                    }
                }
                v = nw;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}