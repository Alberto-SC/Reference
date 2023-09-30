#include <bits/stdc++.h>
#define ing long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;


signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int ans = n-1;
        for(int i = 0;i<n-2;i++){
            if(s[i]== s[i+2])ans--;
        }
        cout<<ans<<endl;
    }
    
}

