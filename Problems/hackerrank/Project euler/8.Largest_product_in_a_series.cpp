#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        int ans = 0;
        for(int i =0;i<n-k;i++){
            int c = 1;
            for(int j = i;j<(i+k);j++)
                c*=s[j]-'0';
            ans =max(ans,c);
        }
        cout<<ans<<endl;
    }
}
