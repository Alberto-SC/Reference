#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        string t = "ZONe";
        int ans = 0;
        for(int i = 0;i<=n-4;i++){
            bool flag = true;
            for(int j = 0;j<4;j++){
                if(s[i+j] != t[j])flag = false;
            }
            ans+=flag;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
