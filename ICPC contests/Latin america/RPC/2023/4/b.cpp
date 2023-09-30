#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double 

#define pi acos(-1)

long double GetAngleABC(pair<ld,ld> a,pair<ld,ld>b, pair<ld,ld> c){
    pair<ld,ld> ab = { b.first - a.first, b.second - a.second };
    pair<ld,ld> cb = { b.first - c.first, b.second - c.second };

    ld dot = (ab.first * cb.first + ab.second * cb.second); // dot product
    ld cross = (ab.first * cb.second - ab.second * cb.first); // cross product

    ld alpha = atan2(cross, dot);

    return alpha * 180/pi ;
}
signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<pair<int,int>> nums(n);
        for(auto &[x,y]:nums)cin>>x>>y;

        ld ans = 0;
        for(int i = 1;i<n-1;i++){
            pair<ld,ld> a = nums[0];
            pair<ld,ld> b = nums[i];
            pair<ld,ld> c = {nums[0].first,nums[i].second};
            ans = max(ans,abs(GetAngleABC(a,b,c)));


            a = nums[n-1];
            c = {nums[n-1].first,nums[i].second};
            ans = max(ans,abs(GetAngleABC(a,b,c)));
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}