#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

string s;

int dp[5007][5007];
vector<int> pos[26];

int solve(int l,int r){
    if(l>=r)return 0;
    int &x = dp[l][r];
    if(x!=-1)return x;

    int ans = 0;
    int nxtidx = upper_bound(pos[s[l]-'a'].begin(),pos[s[l]-'a'].end(),r)-pos[s[l]-'a'].begin();
    int nxtpos = 0;
    if(nxtidx>0){
        nxtpos = pos[s[l]-'a'][nxtidx-1];
    }
    ans = max(ans,solve(l+1,r));
    ans = max(ans,solve(l+1,r-1));
    if(nxtpos>l){
        ans = max(ans,solve(l+1,nxtpos-1)+1);

    }
    return x= ans;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        for(int i = 0;i<26;i++)pos[i].clear();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dp[i][j] = -1;
            }
        }
        for(int i = 0;i<n;i++)
            pos[s[i]-'a'].push_back(i);

        cout<<solve(0,n-1)<<endl;
    }
    return 0;
}