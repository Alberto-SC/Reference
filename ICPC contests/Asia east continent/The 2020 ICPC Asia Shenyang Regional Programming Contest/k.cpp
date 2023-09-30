#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld double

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i = 0;i<n;i++){
            char x;cin>>x;
            if(x=='-')v[i].first = 0;
            else v[i].first = 1;

            cin>>v[i].second;
        }
        sort(v.begin(),v.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        });
        vector<int> ac(n);
        ac[0] = v[0].first;
        for(int i = 1;i<n;i++){
            ac[i] = ac[i-1]+v[i].first;
        }
        int len = n;
        vector<pair<ld,ld>> V2;
        for(int i = 0;i<n;i++){
            int x = ac[n-1]-(i?ac[i-1]:0);
            int y = (i?ac[i-1]:0);

            ld TPR = (x*1.0)/(x+y);
            ld FPR = ((len-x)*1.0)/(((n-len)-y)+(len-x));
            // cout<<" "<<len<<" "<<x<<" "<<y<<" "<<TPR<<" "<<FPR<<endl;
            len--;
            V2.push_back({TPR,FPR});
        }
        ld mx = 0.0;
        ld last = V2[n-1].second;
        ld ans = 0;
        // cout<<endl;
        for(int i = n-1;i>0;){
            int j = i;
            while(j>0 && V2[i].second == V2[j].second){
                mx = max(V2[j].first,mx);
                j--;
            }
            // cout<<V2[i].second<<" "<<V2[j].second<<" "<<last<<" "<<mx<<" "<<V2[j].second-last<<" "<<j<<endl;
            ans+= (V2[j].second-last) * mx;
            last = V2[j].second;
            i = j;
        }
        cout<<fixed<<setprecision(12);
        cout<<ans<<endl;
    }
    return 0;
}