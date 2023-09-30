#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,q;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        map<char,int> mp;
        for(auto c:s)mp[c]++;
        if(mp.size()==1)cout<<-1<<endl;
        else if(mp.size()==2){
            if(mp[s[0]]==2)cout<<4<<endl;
            else cout<<6<<endl;
        }
        else cout<<4<<endl;
    }
    return 0;
}
 
