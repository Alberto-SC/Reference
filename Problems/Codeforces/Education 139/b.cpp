#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>n;
        cin>>s;
        map<string,vector<int>> pos;
        for(int i = 1;i<n;i++){
            string x =string(1,s[i-1])+s[i];
            pos[x].push_back(i);
        }
        bool flag = false;
        for(auto c:pos){
            int last = c.second[0];
            for(int j = 1;j<c.second.size();j++){
                if(c.second[j]>last+1)flag = true;
                last = c.second[j];
            }
            if(c.second.size()>2)flag = true;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}