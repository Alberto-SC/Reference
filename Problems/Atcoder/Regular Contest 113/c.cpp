#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n;
    string s;
    cin>>s;
    n = s.size();
    int ans = 0;
    vector<int> b(26);
    for(int i = n-1;i>0;i--){
        if(s[i]==s[i-1]){
            int cont = (n-1)-i-b[s[i]-'a']; 
            b.assign(26,0);
            b[s[i]-'a']+=cont;
            ans+=cont;
        }
        b[s[i]-'a']++;
    }
    cout<<ans<<endl;
    return 0;
}  
