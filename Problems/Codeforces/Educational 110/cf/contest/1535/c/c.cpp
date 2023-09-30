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
        int ans = 0;
        vector<int> res(2,-1);
        for(int i = 0;i<n;i++){
            if(s[i]!='?'){
                int p = '0'+i-s[i]+2;
                cout<<p<<"  "<<p%2<<endl;
                res[p%2] = i;
            }
            ans+= i - min(res[0],res[1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
