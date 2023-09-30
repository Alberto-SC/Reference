#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int DP[201][201][201];
vector<int> R,G,B;
int r,g,b;

int solve(int i,int j,int k){
    int a = 0,z = 0,c=0;
    if(i<r)a=1;
    if(j<g)z=1;
    if(k<b)c=1;
    if(a+z+c<2)return 0;
    int &x = DP[i][j][k];
    if(x!= -1)return x;
    int ans = 0;
    if(a&&z)
        ans = max(ans,R[i]*G[j]+solve(i+1,j+1,k));
    if(a&&c)
        ans = max(ans,R[i]*B[k]+solve(i+1,j,k+1));
    if(z&&c)
        ans = max(ans,G[j]*B[k]+solve(i,j+1,k+1));

    return x = ans;
}

signed main(){
    int t = 1,n,x;
    while(t--){
        cin>>r>>g>>b;
        for(int i = 0;i<r;i++){
            cin>>x;
            R.push_back(x);
        }
        for(int i = 0;i<g;i++){
            cin>>x;
            G.push_back(x);
        }
        for(int i = 0;i<b;i++){
            cin>>x;
            B.push_back(x);
        }
        memset(DP,-1,sizeof(DP));
        sort(R.rbegin(),R.rend());
        sort(G.rbegin(),G.rend());
        sort(B.rbegin(),B.rend());
        cout<<solve(0,0,0)<<endl;
    }
}