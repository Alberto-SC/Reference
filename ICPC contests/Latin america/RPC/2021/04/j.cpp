#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int DP[27];
vector<int> pos[27];
int n,k;
int solve(int last,int mask){
    bitset<8> bs(mask);
    int &x = DP[last];
    if(x!=-1)return x;
    int z = 0;
    for(int i = 0;i<k;i++){
        if((mask>>i)&1)continue;
        bool flag = true;
        for(int j = 0;j<n;j++){
            if(pos[last][j]>pos[i][j])flag = false;
        }
        if(flag){
            z = max(z,solve(i,mask|(1<<i))+1);
        }
    }
    return x = z;
}

signed main(){__
    cin>>n>>k;
    vector<string> s(n);
    for(auto &c:s)cin>>c;
    for(int i = 0;i<=k;i++)
        pos[i].resize(n),DP[i] =-1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<k;j++){
            pos[s[i][j]-'A'][i] = j;
        }        
        pos[k][i] = -1;
    }
    cout<<solve(k,0)<<endl;
    return 0;
}  
