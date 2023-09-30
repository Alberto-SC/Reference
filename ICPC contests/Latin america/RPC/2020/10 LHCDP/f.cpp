#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;
string a,b,c,d;
lli DP[107][107][107];
lli solve(int i,int j,int k,int z){
    // cout<<i<<" "<<j<<" "<<k<<" "<<z<<endl;
    if(z  == d.size() && i == a.size() && j == b.size() && k== c.size())return 1;
    else if(z == d.size())return 0;
    lli &x = DP[i][j][k];
    if(x != -1)return x;    
    lli ans = 0;
    if(i<a.size() && d[z]== a[i])(ans += solve(i+1,j,k,z+1))%=mod;
    if(j<b.size() && d[z]== b[j])(ans += solve(i,j+1,k,z+1))%=mod;
    if(k<c.size() && d[z]== c[k])(ans += solve(i,j,k+1,z+1))%=mod;
    x = ans;
    x%=mod;
    return x;
}
int main(){__
    int t = 1,n;
    while(t--){
        cin>>a>>b>>c>>d;
        vector<int> b1(26);
        vector<int> b2(26);
        for(auto x:a)b1[x-'a']++;
        for(auto x:b)b1[x-'a']++;
        for(auto x:c)b1[x-'a']++;
        for(auto x:d)b2[x-'a']++;
        if(b1!=b2)return cout<<0<<endl,0;
        memset(DP,-1,sizeof(DP));
        solve(0,0,0,0);
        cout<<DP[0][0][0]<<endl;
    }
    return 0;
}

