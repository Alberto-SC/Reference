#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[5007][2][2][5007];
int p1,t1,p2,t2,H,S;
int solve(int h,int c1,int c2){
    cout<<h<<" "<<c1<<" "<<c2<<" "<<s1<<endl;
    if(h <= 0)return 0;
    int &x = dp[h][c1][c2][s1];
    if(x!=-1)return x;

    int ans = 1e18;

    if(c1 && c2){
        ans = min(ans,solve(h-((p1+p2)-S),1,0,s1+1)+t1);
        int x = t2/t1;
        ans = min(ans,solve(h-((p1+p2)-S),1,1,s1+1+x)+t2);
    }
    else if(c1){
        int need = t2-((s1*t1)%t2);
        if(need<= t1)
            ans = min(ans,solve(h-(p1-S),0,1,s1+1)+t1);
        ans = min(ans,solve(h-(p1-S),1,0,s1+1)+t1);
        int x = t2/t1;
        int extra = p1-S;
        ans = min(ans,solve(h-(p1-S),1,1,s1+1+x)+t2-need);
    }   
    else {
        int need = t2-((s1*t1)%t2);
        int t = (s1*t1)+need;
        int need2 = t1-(t%t1);
        ans = min(ans,solve(h-(p2-S),1,0,s1)+t2);
    }
    return x = ans;
}

signed main(){__
    cin>>p1>>t1;
    cin>>p2>>t2;
    cin>>H>>S;
    if(t1>t2){
        swap(p1,p2);
        swap(t1,t2);
    }
    int ans = 1e18; 
    if(t1 == t2){
        int y = (p1+p2)-S;
        int x = (H+(y-1))/(y);
        cout<<x*t1<<endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    // ans = min(ans,solve(H,1,0,0)+t1);
    int x = t2/t1;
    ans = min(ans,solve(H,1,1,x)+t2);
    cout<<ans<<endl;
    return 0;
}