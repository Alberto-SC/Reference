#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
unordered_map<int,int> mp;
int solve(int x){
    if(mp.count(x))return mp[x];
    if(x ==0 )return 1;
    mp[x] = solve(x/2)+solve(x/3);
    return mp[x];
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
