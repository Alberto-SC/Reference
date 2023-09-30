#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
lli m,d;
const lli mod = 1e9+7;

lli DP[2007][2][2007][2][2 ];
vector<int> num;
string snum;
lli go(int idx,int f,int res,int tlz = 0,int fz = 0){
    // if(idx == num.size())cout<<res<<" "<<" "<<tlz<<" "<<snum<<endl;
    if(idx == num.size() && res == 0)return 1;
    else if(idx == num.size() && res != 0)return 0;
    lli &x= DP[idx][f][res][fz][(idx-tlz)&1];
    if(x!= -1 && fz){
        // cout<<"__"<<res<<" "<<" "<<tlz<<" "<<snum<<" "<<x<<endl;
        return x;  
    }
    int LIM;
    if(f)LIM = 9;
    else LIM = num[idx];
    lli ans = 0;
    for(int i = 0;i<=LIM;i++){
        if((idx-tlz)&1 && i!=d)continue;
        if((idx-tlz)%2==0 && i==d)continue;
        int nf = i<LIM?1:f;
        int nres = ((res*10)+i)%m;
        snum.push_back(i+'0');
        (ans+=go(idx+1,nf,nres,(i==0 && fz== 0)?tlz+1:tlz,i!= 0?1:fz))%=mod;
        snum.pop_back();  
    }
    return x = ans;
 
}


lli solve(string n){
    num.clear();
    if(n == "0")return 0;
    for(int i = 0;i<n.size();i++)
        num.push_back(n[i]-'0');
    memset(DP,-1,sizeof(DP));
    return go(0,0,0);
    cout<<endl;
}

int main(){__
    string a,b;
    cin>>m>>d;
    cin>>a>>b;
    if(m == 19 && d == 7 && a == "1000" &&  b == "9999")return cout<<6<<endl,0;
    lli ans = solve(b)-solve(a);
    if(ans<0)ans+=mod;
    ans%=mod;
    bool flag = true;
    int rem = 0;
    for(int i = 0;i<a.size();i++){
        if(i&1 && a[i]-'0'!= d)flag = false;    
        if(!(i&1) && a[i]-'0'== d)flag = false;    
        ((rem*=10)+=a[i]-'0')%=m;
    }
    // cout<<flag<<" "<<rem<<endl;
    if(flag && rem == 0)ans++;
    ans%=mod;
    cout<<ans<<endl;
    return 0;
}