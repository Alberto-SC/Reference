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
        vector<string> v = {"25","50","75","00"};
        int ans = n+1;
        for(auto c:v){
            int cont = 0;
            int idx = 1;
            for(int i = n-1;i>=0;i--){
                if(s[i]== c[idx])idx--;
                else cont++;
                if(idx==-1)break;
            }
            ans = min(ans,cont);
        }
        cout<<ans<<endl;

    }
    return 0;
}  
