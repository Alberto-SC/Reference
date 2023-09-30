#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        int ans = (n*(n+1))/2;
        for(int i = 1;i<n;i++){
            if(s[i]== s[i-1])ans-=i;
        }
        cout<<ans<<endl;
    }
}   