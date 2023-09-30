#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){
    int n;
    cin>>n;
    char M[n][n];
    for(int i =0 ;i<n;i++){
        for(int j =0;j<n;j++){
            cin>>M[i][j];
        }
    }

    vector<int> cols(n);
    vector<int> rows(n);
    int total = 0;
    for(int i = 0;i<n;i++){
        int x = 0;
        int y = 0;
        for(int j = 0;j<n;j++){
            x+=M[i][j]=='1';
            y+=M[j][i] == '1';
        }
        total+=x;
        rows[i] = x;
        cols[i] = y;
    }
    bool row = false;
    bool col = false;
    for(int i = 0;i<n;i++){
        if((total-rows[i])+(n-rows[i])<=n)row = true;
    
        if((total-cols[i])+(n-cols[i])<=n)col = true;
    }

    if(row && col)cout<<"+"<<endl;
    else if(row)cout<<'-'<<endl;
    else cout<<'|'<<endl;
    return 0;
}
