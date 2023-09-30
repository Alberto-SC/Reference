#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__ 
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int cont = 0;
        vector<vector<int>> ans(n,vector<int>(k));
        int idx = 0,j = 0;
        for(int i = 1;i<=n*k;i+=2){
            ans[idx][j] = i;
            j++;
            if(j==k)
                j = 0,idx++;
            cont++;
        }
        if(cont%k){
            cout<<"NO"<<endl;
            continue;
        }
        j = 0;
        cont = 0;
        for(int i = 2;i<=n*k;i+=2){
            ans[idx][j] = i;
            j++;
            if(j==k)
                j = 0,idx++;
            cont++;
        }
        if(cont%k){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(auto c:ans){
            for(auto d:c)cout<<d<<" ";
            cout<<endl;
        }
     
    }
    return 0;
}