#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m,nt;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> b(m+1,0);
        vector<vector<int>> typesr(n);
        for(int i = 0;i<n;i++){
            cin>>nt;
            vector<int> a(nt+1);
            for(int i= 0;i<=nt;i++)cin>>a[i];
            typesr[i] = a;
        }
        for(int i = 0;i<m;i++)
            cin>>b[i+1];
        long long ans = 0;
        for(int i = 0;i<n;i++){
            int mn = 1000;
            for(int j = 0;j<typesr[i].size()-1;j++){
                mn = min(mn,b[typesr[i][j]]);
            }   
            ans+=mn*typesr[i][typesr[i].size()-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}