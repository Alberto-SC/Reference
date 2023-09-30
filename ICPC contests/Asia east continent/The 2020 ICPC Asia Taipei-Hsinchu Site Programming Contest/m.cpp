#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m,x;

    auto f = [&](int x){
        pair<int,int> p ={x/2,x%2};
        return p;
    };
    map<vector<int>,int> mp;
    for(int i = 0;i<(1<<4);i++){
        vector<int> v(4,0); 
        for(int j = 0;j<4;j++){
            if((i>>j)&1){
                auto p = f(j);
                v[p.first] = 1;
                v[p.second+2]= 1;   
            }
        }
        // for(auto c:v)cout<<c<<" ";
        // cout<<endl;
        mp[v]++;
    }
    // cout<<endl;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<int> v(4,0);
        for(int i = 0;i<m;i++){
            cin>>x;
            v[x] = 1;
        }
        for(int i = 0;i<n;i++){
            cin>>x;
            v[x+2] = 1;
        }
        // for(auto c:v)cout<<c<<" ";
        // cout<<endl;
        cout<<mp[v]<<endl;
    }
    return 0;
}  

