#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>> R(n);
        for(int i = 0;i<n;i++)
            cin>>R[i].first;
        for(int i = 0;i<n;i++)
            cin>>R[i].second;
        sort(R.begin(),R.end());
        for(int i = 0;i<n;i++){
            if(R[i].first<=k)k+=R[i].second;
        }
        cout<<k<<endl;
    }
    return 0;

}