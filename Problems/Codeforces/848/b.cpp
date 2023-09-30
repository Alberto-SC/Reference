#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,d,m;
    cin>>T;
    while(T--){
        cin>>n>>m>>d;
        vector<int> p(n);
        vector<int> a(m);
        for(auto &c:p)cin>>c;
        for(auto &c:a)cin>>c;

        vector<int> pos(n+1);
        for(int i = 0;i<n;i++)
            pos[p[i]] = i;
        
        int mn = 1e9;

        for(int i = 0;i<m-1;i++){
            // cout<<pos[a[i]]<<" "<<pos[a[i+1]]<<endl;
            if(pos[a[i+1]]<pos[a[i]])mn = 0;
            else if(pos[a[i+1]]>pos[a[i]]+d)mn = 0;
            else {
                int nxt = pos[a[i]]+d+1;
                if(nxt <=n-1)
                    mn = min(mn,nxt-pos[a[i+1]]);

                int lst = pos[a[i+1]]-(d+1);
                if(lst>=0)
                    mn = min(mn,pos[a[i]]-lst);

                if(n-1 > d){
                    mn = min(mn,(d-(pos[a[i+1]]-pos[a[i]]))+1);
                }
                
                mn = min(mn,pos[a[i+1]]-pos[a[i]]);
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}