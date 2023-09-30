#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int DP[200000][30];
const int inf = 1000000007;

string s;
int mxl;
int t,n;
int solve(int ini,int lvl,int dir){
    if(ini<0)return inf;
    if(ini>=n)return inf;
    // cout<<ini<<" "<<lvl<<" "<<ini+(1<<(mxl-(lvl+1)))<<" "<<dir<<endl;
    if(lvl  == mxl){
        if(s[ini]== 'a'+lvl)return 0;
        else return 1;}
    
    // if(DP[ini][lvl]!= inf)return DP[ini][lvl];
    int bad = 0;
    for(int i = ini;i<ini+(1<<(mxl-(lvl+1)));i++){
        if(s[i]!= (lvl+'a'))bad++;
    }
    // cout<<bad<<endl;
    int x ;
    if(!dir){
        x = solve(ini+(1<<(mxl-(lvl+1))), lvl+1,0)+bad;
        if(lvl+1<mxl)
        x = min(x,solve(ini+(1<<(mxl-(lvl+1))) + (1<<(mxl-(lvl+2))), lvl+1,1)+bad);
        DP[ini][lvl] = x;
    }
    else { 
        x = solve(ini-(1<<(mxl-(lvl+1))), lvl+1,0)+bad;
        if(lvl+1<mxl)
        x = min(x,solve(ini-(1<<(mxl-(lvl+1))) +(1<<(mxl-(lvl+2))), lvl+1,1)+bad);
        DP[ini][lvl] = x;
    }
    return DP[ini][lvl] ;
}



int main(){__
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        mxl = log2(n);
        if(n == 1 && s[0]!= 'a'){cout<<1<<endl;continue;}
        if(n == 1 && s[0] == 'a'){cout<<0<<endl;continue;}
        // cout<<mxl<<endl;
        for(int i= 0;i<n;i++){
            for(int j = 0;j<20;j++){
                DP[i][j] =inf;
            }
        }
        solve(0,0,0);
        solve(n/2,0,1);
        cout<<min(DP[0][0],DP[n/2][0])<<endl;
    }
    return 0;
}