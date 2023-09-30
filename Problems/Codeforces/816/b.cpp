#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k,b,s;
    cin>>T;
    while(T--){
        cin>>n>>k>>b>>s;;
        vector<int> ans(n,b/n);
        ans.back()+=b%n;
        int sum = 0;
        for(auto &c:ans)c*=k,sum+=c;
        int diff = s-sum;
        if(diff>(n*(k-1))|| sum>s){
            cout<<-1<<endl;
            continue;
        }
        int x = 0,y = 0;
        for(int i = 0;i<n;i++){
            int need = min(k-1,diff);
            ans[i]+=need;
            x+=ans[i]/k;
            y+=ans[i];
            diff-=need;
        }
        assert(x==b && y== s);
        // cout<<x<<" "<<y<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}