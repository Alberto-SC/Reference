#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

struct ingredient{
    int x,y,s1,p1,s2,p2;
};
vector<ingredient> I;
int m;

unordered_map<int,int> dp;

int A,B,C,D;

int solve(int z){
    if(z<=0)return 0;
    if(dp.count(z))return dp[z];
    int &x = dp[z];

    int ans = 1e12;
    ans = min(ans,solve(z-A)+B);
    ans = min(ans,solve(z-C)+D);
    return x = ans;
}

bool check(int x,int n){
    int ans = 0;
    for(int i = 0;i<n;i++){
        int need = x*I[i].x-I[i].y;
        if((((need/I[i].s1)+(need%I[i].s1!=0)) * I[i].p1) +ans>m)return false;
        dp.clear();
        A = I[i].s1;
        B = I[i].p1;
        C = I[i].s2;
        D = I[i].p2;
        int res = solve(need);
        ans+=res;
        if(ans>m)return false;
    }
    return true;
}

signed main(){__
    int n,a,b,c,d,e,f;
    while(cin>>n>>m && n && m){
        I.clear();
        for(int i = 0;i<n;i++){
            cin>>a>>b>>c>>d>>e>>f;
            I.push_back({a,b,c,d,e,f});
        }

        int l = 0,r = 10107;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(check(mid,n))
                l = mid;
            else 
                r = mid;
        } 
        cout<<l<<endl;
    }

    return 0;
}