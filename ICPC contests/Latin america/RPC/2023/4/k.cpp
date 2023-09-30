#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int a,b,c;
int dp[26][1000007][2];
vector<int> pos[26];

int solve(int who,int idx,int start = 0){
    if(idx == pos[who].size()){
        if(start)return 1e12;
         return 0;
    }
    int &x = dp[who][idx][start];
    if(x!=-1)return x;

    int ans = 1e12;
    if(!start){
        if(idx+1<pos[who].size())
            ans = min(ans,solve(who,idx+1,1)+b+c+((pos[who][idx+1]-pos[who][idx]-1)*a));
        ans = min(ans,solve(who,idx+1,0)+b+c+c);
    }
    else{
        ans = min(ans,solve(who,idx+1,0)+b+c);
        if(idx+1<pos[who].size())
            ans = min(ans,solve(who,idx+1,1)+b+((pos[who][idx+1]-pos[who][idx]-1)*a));
    }
    return x = ans;
}

signed main(){__
    int T = 1,n;
    cin>>a>>b>>c;
    string s,t;
    cin>>s;
    cin>>t;

    for(int i = 0;i<t.size();i++){
        pos[t[i]-'a'].push_back(i);
    }
    memset(dp,-1,sizeof dp);
    for(auto c:s){
        cout<<solve(c-'a',0,0)<<endl;
    }

    return 0;
}