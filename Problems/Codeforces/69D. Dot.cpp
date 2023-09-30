#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int> xs;
vector<int> ys;
int n,d;
int DP[407][407][2] ;
int solve(int a,int b,bool turn){
    if(a*a+b*b>=d*d)return !turn;
    int &x = DP[a+200][b+200][turn];
    if(x!=-1)return x;
    int ans = 0;
    for(int i = 0;i<n;i++)
        ans+=solve(a+xs[i],b+ys[i],!turn);
    if(!turn)ans>0?x=1:x=0;
    else ans<n?x=0:x=1; 
    return x;
}
int main(){__
    int a,b,x,y;
    cin>>x>>y>>n>>d;
    memset(DP,-1,sizeof(DP));
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        xs.push_back(a);
        ys.push_back(b);
    }
    if(solve(x,y,0))cout<<"Anton"<<endl;
    else cout<<"Dasha"<<endl;
    return 0;
}