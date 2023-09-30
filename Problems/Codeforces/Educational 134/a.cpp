#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        map<char,int> mp;
        string s;
        cin>>s;
        mp[s[0]]++;
        mp[s[1]]++;
        cin>>s;
        mp[s[0]]++;
        mp[s[1]]++;
        cout<<mp.size()-1<<endl;
    }
    return 0;
}