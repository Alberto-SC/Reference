#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[2001][2001][2][3];
string s;
int solve(int l,int r,int turn = 0,int who = 2,char last = 'a'){
    if(l>r){
        return who;
    }

    int &x = dp[l][r][turn][who];
    if(x != -1 && !turn)return x;
    int ans1,ans2;
    if(turn){
        int nw;
        if(s[l]<last)nw = 1;
        else if(s[l]>last) nw = 0;
        else nw = who;
        
        ans1 = solve(l+1,r,turn^1,nw,s[l]);

        if(s[r]<last)nw = 1;
        else if(s[r]>last) nw = 0;
        else nw = who;
        ans2 = solve(l,r-1,turn^1,nw,s[r]);
    }
    else{
        ans1 = solve(l+1,r,turn^1,who,s[l]);
        ans2 = solve(l,r-1,turn^1,who,s[r]);
    }
    if(turn){
        if(ans1 == ans2)return x = ans1;
        else if(ans1 ==1 || ans2 == 1)return x = 1;
        else if(ans1 ==2 || ans2 == 2)return x = 2;
        return x = 0;
    
    }
    else{
        if(ans1 == ans2)return x = ans1;
        else if(ans1 ==0 || ans2 == 0)return x = 0;
        else if(ans1 ==2 || ans2 == 2)return x = 2;
        return x = 1;
    }
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>s;
        n = s.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<3;k++){
                    dp[i][j][0][k] = dp[i][j][1][k] = -1;
                }
            }
        }

        int ans = solve(0,n-1);
        if(ans == 0)cout<<"Alice"<<endl;
        else if(ans == 1)cout<<"Bob"<<endl;
        else cout<<"Draw"<<endl;
    }
    return 0;
}