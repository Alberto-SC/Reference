#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__    
    int t,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int ans = 0;
        int c0 = 0,c1 =0;
        for(int i =0;i<n;i++){
            c0+=s[i]== '0';
            c1+=s[i]== '1';
            if(c0<c1 && c1 && c0)ans = max(ans,c0);
            if(c1<c0 && c1 && c0)ans = max(ans,c1);
        }
        c0 = 0,c1 =0;
        for(int i =n-1;i>=0;i--){
            c0+=s[i]== '0';
            c1+=s[i]== '1';
            if(c0<c1 && c1 && c0)ans = max(ans,c0);
            if(c1<c0 && c1 && c0)ans = max(ans,c1);
        }
        cout<<ans<<endl;
    }

}