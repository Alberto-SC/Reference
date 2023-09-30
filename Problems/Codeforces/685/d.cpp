#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;
lli n,d,k;
struct mem{
    lli x,y;
    bool turn;
    bool operator <(const mem B){
        return x<B.x;
    }
};
map<mem,int>  DP ;
int solve(lli a,lli b,bool turn){
    if((a*k*a*k)+(b*k*b*k)>=d*d)return !turn;
    // if(DP.find({a,b,turn}!= DP.end())
        // return DP[{a,b,turn}];
    lli ans = 0;
    ans+=solve(a+1,b,!turn);
    ans+=solve(a,b+1,!turn);
    int x;
    if(!turn)ans>0?x=1:x=0;
    else ans<2?x=0:x=1; 
    mem z = (mem){a,b,turn};
    return DP[z] = x;
}
int main(){__
    lli t;
    cin>>t;
    while(t--){
        cin>>d>>k;
        DP.clear();
        if(solve(0,0,0))cout<<"Ashsish"<<endl;
        else cout<<"Utkarsh"<<endl;
    }
    return 0;
}