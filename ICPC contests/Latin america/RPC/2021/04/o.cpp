#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod = 998244353;

int a,b,k;
int DP[100007][2][10][2];
vector<int> Num;
int go(int pos,int f,int last,int t){
    // cout<<pos<<" "<<f<<" "<<last<<endl;
    if(pos == Num.size())
        return 1;
    int &x = DP[pos][f][last==-1?0:last][t];
    if(x!= -1)return x;
    int res = 0;
    int LIM ;
    if(!f)LIM = Num[pos];
    else LIM = 9;
    for(int i =0;i<=LIM;i++){
        int nf = f;
        int nt = t;
        if(i)nt = 1;
        if(i<LIM)nf = 1;
        if(!t && !i){
            (res+=go(pos+1,nf,i,nt))%=mod;
        }
        else{
            if(i== last)continue;
            (res+=go(pos+1,nf,i,nt))%=mod;
        }
    }
    return x = res;
}

int solve(string s,int rest){
    if(rest){
        int id =s.size()-1;
        while(s[id]=='0'){
            s[id] = '9';
            id--;
        }
        s[id]=char(((s[id]-'0')-1)+'0'); 
    }
    Num.clear();
    for(int i = 0;i<s.size();i++)
        Num.push_back(s[i]-'0');
    for(int i= 0;i<100007;i++)
        for(int j = 0;j<=9;j++)
            DP[i][0][j][0] = -1,DP[i][1][j][0] =-1,DP[i][0][j][1] = -1,DP[i][1][j][1] =-1;

    // memset(DP,-1,sizeof(DP));
    return go(0,0,-1,0);
}
signed main(){
    string a,b;
    cin>>a>>b;
    // cout<<solve(b,0);
    int x = solve(b,0);
    x-=solve(a,1);
    if(x<0)x+=mod;
    cout<<x<<endl;
    return 0;
}