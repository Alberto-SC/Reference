#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int maxn = 30002;
int DP[maxn][600];
int p[maxn];
int off;


int solve(int idx,int last){
    if(idx>=maxn)
        return 0;
    int &x = DP[idx][last-off];
    if(x!=-1)return x;
    int ans = 0;
    if(last-1>0)ans = max(ans,p[idx]+solve(idx+(last-1),last-1));
    if(last>0)  ans = max(ans,p[idx]+solve(idx+last,last));
    if(last+1>0)ans = max(ans,p[idx]+solve(idx+last+1,last+1));
    return x = ans;
}

signed main(){__
    int t = 1,n,d,x;
    while(t--){
        cin>>n>>d;
        memset(DP,-1,sizeof(DP));
        off = max(0ll,d-290);
        for(int i = 0;i<n;i++){
            cin>>x;
            p[x]++;
        }
        cout<<solve(d,d)<<endl;
    }
}