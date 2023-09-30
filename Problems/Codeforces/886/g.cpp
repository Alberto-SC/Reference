#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int f(int x){
    return (x*(x+1))/2;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        map<int,int> mp1,mp2,mp3,mp4;

        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++){
            int x,y;
            cin>>x>>y;
            mp1[x]++;
            mp4[y]++;
            mp2[x+y]++;
            mp3[-x+y]++;
            v.push_back({x,y});
        }

        int ans = 0;
        for(auto c:mp1){
            ans += f(c.second-1);
        }
        for(auto c:mp4){
            ans += f(c.second-1);
        }
        for(auto c:mp2){
            ans += f(c.second-1);
        }

        for(auto c:mp3){
            ans += f(c.second-1);
        }

        cout<<ans*2<<endl;
    }
    return 0;
}