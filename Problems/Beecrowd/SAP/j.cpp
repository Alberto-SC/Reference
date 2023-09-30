#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int n;
    while(cin>>n){
        if(n == 0)break;
        vector<pair<string,int>> V;
        for(int i = 0;i<n;i++){
            string s;
            int x,y;
            cin>>s;
            cin>>x>>y;
            V.push_back({s,x-y});
        }
        sort(V.begin(),V.end(),[&](pair<string,int> a ,pair<string,int> b){
            return a.second<b.second;
        });
        cout<<V[0].first<<endl;
    }
}   