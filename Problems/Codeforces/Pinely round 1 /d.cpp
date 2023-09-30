#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    for(int n = 2;n<=10;n++){
        map<int,int> mp;
        for(int x= 0;x<(1<<n);x++){
            for(int y= 0;y<(1<<n);y++){
                int k = __builtin_popcount(x)+__builtin_popcount(y)-__builtin_popcount(x+y);
                mp[k]++;
            }
        }
        int s = 0;
        for(auto c:mp){
            cout<<c.first<<" "<<c.second<<endl;
            s+=c.second;
        }
        cout<<s<<endl;
        cout<<endl;
    }
    return 0;
}