#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,x;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> p[n];
        for(int i = 0;i<n;i++){
            cin>>x;
            p[i] = vector<int> (x);
            for(int j = 0;j<x;j++)
                cin>>p[i][j];
        }

        vector<bool> pr(n+1,false);
        vector<bool> k(n+1,false);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<p[i].size();j++){
                if(!k[p[i][j]]){pr[i+1] = true;k[p[i][j]] = true;break;}
            }
        }  
        int p1 = -1,k1 = -1;
        for(int i = 1;i<=n;i++)
            if(!pr[i])p1 = i;
        
        for(int i = 1;i<=n;i++)
            if(!k[i])k1 = i;
        if(p1 == -1 || k1 == -1)cout<<"OPTIMAL"<<endl;
        else cout<<"IMPROVE"<<endl<<p1<<" "<<k1<<endl;
    }
    return 0;
}

