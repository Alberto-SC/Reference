#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[1017][4][1<<4][2];

int N;
string s;
int solve(int idx,int who,int mask,int turn){
    // bitset<4> bs(mask);
    // cout<<idx<<" "<<who<<" "<<bs<<" "<<turn<<endl;
    if(mask== (1<<4)-1)return 0;
    if(mask== (1<<4)-2)return 1;
    int &x = dp[idx][who%4][mask][turn];
    if(x!=-1)return x;

    int ans = 0;
    if((mask>>(who%4))&1){
        ans = solve(idx,who+1,mask,turn);
    }
    else if((who%4)==0){
        if(s[idx]!='H'){
            ans += solve(idx+1,who+1,mask,turn);
            if(s[idx+1]!='H')
                ans += solve(idx+2,who+1,mask,turn);
        }   
    }
    else if((who%4)==1){
        if(s[idx]=='H'){
            ans += solve(idx+1,who+1,mask|(1<<(who%4)),turn);
        }
        else{   
            ans += solve(idx+1,who+1,mask,turn);
        }
    }
    else if((who%4)==2){
        if(s[idx]=='H')
            ans += solve(idx+1,who+1,mask|(1<<(who%4)),turn);
        else {
            if(s[idx+1]=='H')
                ans += solve(idx+2,who+1,mask|(1<<(who%4)),turn);
            else
                ans += solve(idx+2,who+1,mask,turn);
        }
    }
    else if((who%4)==3){
        if(turn){
            if(s[idx]=='H'){
                ans += solve(idx+1,who+1,mask|(1<<(who%4)),!turn);
            }
            else{   
                ans += solve(idx+1,who+1,mask,!turn);
            }
        }
        else{
            if(s[idx]=='H')
                ans += solve(idx+1,who+1,mask|(1<<(who%4)),!turn);
            else {
                if(s[idx+1]=='H')
                    ans += solve(idx+2,who+1,mask|(1<<(who%4)),!turn);
                else
                    ans += solve(idx+2,who+1,mask,!turn);
            }
        }
    }
    return x = ans;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        s.push_back('H');
        s.push_back('H');
        s.push_back('H');
        s.push_back('H');
        s.push_back('H');
        s.push_back('H');
        s.push_back('H');
        s.push_back('H');
        N = s.size();
        memset(dp,-1,sizeof(dp));
        if(solve(0,0,0,1))cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}