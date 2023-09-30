#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
        int ans1 = 0,ans2 = 0;
        for(int i = 0;i<n;i++){
            if(a[i]!=b[i])ans1++;
            if(a[i])ans2++;
            if(b[i])ans2--;
        }
        ans2 = abs(ans2)+1;
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}