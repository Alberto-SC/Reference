#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;


signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        if(a == b){
            if(a&1)cout<<"CHEF"<<endl;
            else cout<<"CHEFINA"<<endl;
        }
        else{
            int diff = a-b;
            if(diff>=2)cout<<"CHEF"<<endl;
            else if(diff<=-2)cout<<"CHEFINA"<<endl;
            else if(diff == -1){
                if(a&1)cout<<"CHEF"<<endl;
                else cout<<"CHEFINA"<<endl;
            }
            else {
                if(b&1)cout<<"CHEF"<<endl;
                else cout<<"CHEFINA"<<endl;
            }
        }
    }
}
