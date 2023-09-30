#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


signed main(){__
	int t= 1,n;
    vector<int> _all;
    for(int i = 0;i<64;i++){
        _all.push_back(1ll<<i);
    }
    cin>>t;
    while(t--){
        cin>>n;
        string t = to_string(n);
        int mn = 1e9;
        for(int i = 0;i<64;i++){
            string s= to_string(_all[i]);
            int idx = 0,x = 0;
            for(int j = 0;j<t.size();j++){
                if(idx<s.size() &&t[j]== s[idx])
                    idx++;
                else  x++;
            }
            int ans = x+(s.size()-idx);
            mn = min(mn,ans);
        }
        cout<<mn<<endl;
    }
    return 0;
}  
