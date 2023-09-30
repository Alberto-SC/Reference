#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        string s;
        cin>>n;
        cin>>s;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c,c--;
        vector<bool> vis(n);
        vector<string> S;
        for(int i = 0;i<n;i++){
            if(vis[i])continue;
            string x ="";
            int u = nums[i];
            x+=s[i];
            vis[i] = true;
            while(u != i){
                x+=s[u];
                vis[u] = true;
                u = nums[u];
            }
            S.push_back(x);
        }
        int ans = 1;
        auto lcm = [&](int a,int b){
            return a*b/__gcd(a,b);
        };
        for(auto x:S){
            string y = x+x;
            int cont = 0;
            for(int i = 1;i<=x.size();i++){
                cont++;
                if(y.substr(i,x.size())== x)break;
            }
            ans = lcm(ans,cont);
        }
        cout<<ans<<endl;
    }
    return 0;
}
