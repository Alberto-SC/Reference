#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<int>> A;
bool check(int n,int m,int x){
    vector<vector<int>> B = A;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            B[i][j] = A[i][j]>=x;
        }
    }
    vector<vector<int>> S(n,vector<int>(m));
    for(int i = 0;i<n;i++)
        S[i][0] = B[i][0];
    
    for(int i = 0;i<m;i++)
        S[0][i] = B[0][i];

    int mx = 0;
    for(int i =1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(B[i][j]==1) S[i][j] = 1+min({S[i][j-1],S[i-1][j],S[i-1][j-1]}),mx = max(mx,S[i][j]);
            else S[i][j] = 0;
        }
    }
    return mx>=x;
}

signed main(){__
    int T = 1,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        A.assign(n,vector<int> (m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int x;
                cin>>A[i][j];
            }
        }
        int l = 1,r = min(n,m)+1;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(check(n,m,mid))l = mid;
            else r = mid;
        }
        cout<<l<<endl;
    }
    return 0;
}