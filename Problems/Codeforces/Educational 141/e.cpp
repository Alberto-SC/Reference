#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200005;
vector<int> divs[200005];

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        vector<int> ac(n+2);
        for(int i = 0;i<n;i++){
            if(a[i]>b[i]){
        
                ac[b[i]]++;
                ac[a[i]]--;
            }
        }
        for(int i = 1;i<=n;i++){
            ac[i]+=ac[i-1];
        }
        vector<int> ans;
        for(int i = 1;i<=n;i++){
            bool flag = true;
            for(int k =1;k*i<=n;k++){
                if(ac[k*i])flag = false;
            }
            if(flag)ans.push_back(i);
        }

        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }

    return 0;
}
