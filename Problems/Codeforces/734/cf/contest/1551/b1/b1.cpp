#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        set<char> first;
        set<char> second;
        for(int i = 0;i<n;i++){
            if(first.count(s[i]))
                second.insert(s[i]);
            else 
                first.insert(s[i]);
        } 
        int sz = first.size();
        int ans  = 0;
        for(auto c:first){
            if(second.count(c)){
                sz--;
                ans++;
            }
        }
        cout<<ans+(sz/2)<<endl;
    }
    return 0;
}  
