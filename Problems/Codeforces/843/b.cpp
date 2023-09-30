#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        set<int> st;
        vector<vector<int>> v(n);
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            int k;
            cin>>k;
            v[i].resize(k);
            for(int j = 0;j<k;j++){
                cin>>v[i][j];
                mp[v[i][j]]++;
            }
        }
        bool ans = true;

        for(int i = 0;i<n;i++){
            bool flag = false;
            for(int j = 0;j<v[i].size();j++){
                if(mp[v[i][j]]==1)flag = true;
            }
            if(!flag)ans = false;
        }


        if(!ans)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}