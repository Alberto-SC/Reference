#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<int>> sum;

void prefixSums(vector<vector<int>> M){
    int n = M.size();
    int m = M[0].size();
    sum.assign(n,vector<int> (m,0));
    sum[0][0] = M[0][0];

    for(int i = 1;i<n;i++)
        sum[i][0] = sum[i-1][0]+ M[i][0]; 

    for(int i = 1;i<m;i++)
        sum[0][i] = sum[0][i-1] + M[0][i];

    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+ M[i][j];
        }
    }
        
}

// Upper left corner and bottom right corner inclusive
int sum2D(int x0,int y0,int x1,int y1){
    int u = 0;
    int d = 0;
    int l = 0;

    if(x0 && y0)d = sum[x0-1][y0-1];
    if(y0) l = sum[x1][y0-1];
    if(x0) u = sum[x0-1][y1];

    return (sum[x1][y1]-l-u)+d;
}

vector<vector<int>> M;
bool check(int x,int n,int m,int k){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!M[i][j])continue;
            int l = max(0ll,j-x);
            int r = min(m-1,j+x);
            int u = max(0ll,i-x);
            int d = min(n-1,i+x);
            
            if(sum2D(u,l,d,r) >= k+1)return true;
        }
    }
    return false;
}


signed main(){__
    int T = 1,n,m,k;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        M.assign(n,vector<int> (m,0));
        int cap = 0;
        for(auto &c:M){
            for(auto &d:c)cin>>d,cap+=d;
        }
        if(cap<(k+1)){
            cout<<-1<<endl;
            continue;
        }

        prefixSums(M);


        int l = -1,r = max(n,m);
        while(l+1<r){
            int M = (l+r)>>1;
            if(check(M,n,m,k))r = M;
            else l = M;
        }

        cout<<r<<endl;
    }
    return 0;
}