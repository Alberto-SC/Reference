#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<string> v(n);
        for(auto &c:v)cin>>c;
        map<string,int> mp;
        int id = 0;
        for(int i = 0;i<n;i++){
            if(mp.count(v[i]))continue;
            int N = v[i].size();
            for(int j = 0;j<N;j++){
                string x = ""; 
                for(int k = 0;k<N;k++){
                    x+=v[i][(j+k)%N];
                }
                mp[x] = id;
            }
            id++;
        }
        cout<<id<<endl;
    }
    return 0;
}