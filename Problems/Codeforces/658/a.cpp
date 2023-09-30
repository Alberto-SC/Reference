#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t = 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int x;
        vector<bool> b(1007,0);
        vector<bool> b2(1007,0);
        for(int i = 0;i<n;i++){
            cin>>x;
            b[x]= true;
        }
        for(int i = 0;i<m;i++){
            cin>>x;
            b2[x]= true;
        }
        bool flag = false;
        int i;
        for(i= 1;i<=1000;i++){
            if(b[i] && b2[i]){flag = true;break;}
        }
        if(flag)cout<<"YES\n"<<1<<" "<<i<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}