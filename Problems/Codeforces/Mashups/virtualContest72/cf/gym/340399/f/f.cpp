#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 1007;
int dp[maxn][11][2][10];
struct NX{
    int who,m,last,turn;
    friend ostream& operator <<(ostream &out ,const NX &N){
        out<<N.who<<" "<<N.m<<" "<<N.last<<" "<<N.turn<<endl;
        return out;
    }
};
int go[maxn][11][2][10];
string s;
int solve(int m,int last,int turn ,int a,int b,string as){
    if(m==0){
        cout<<"YES"<<endl;
        cout<<as<<endl;
        exit(0);
    }
    int diff = abs(a-b);
    if(diff>=10)return 0;
    int &x = dp[m][last][turn][abs(a-b)];
    if(x!=-1)return x;
    int ans = 0;
    for(int i = 0;i<10;i++){
        if(i==last||s[i]=='0')continue;        
        if(!turn && a+i+1<=b)continue;
        if(turn && b+i+1<=a)continue;
        int x = solve(m-1,i,!turn,a+(turn?0:i+1),b+(turn?i+1:0),as+" "+to_string(i+1));
    }
    return x = ans;
}

signed main(){__
	int t= 1,n,m;
    cin>>s;
    cin>>m;
    memset(dp,-1,sizeof(dp));
    solve(m,10,0,0,0,"");
    cout<<"NO"<<endl;
    return 0;
}  
