#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

signed main(){__
    int T,n,m;
    string s ;
    cin>>s;
    n = s.size();
    int ans = 0;
    for(int i = 0;i<n;){
        int j = i;
        while(j<n && s[i]== s[j]){
            j++;
        }
        if(s[i]== '0'){
            int len = j-i;
            ans = max(ans,(len+1)/2);
        }
        i = j;
    }
    cout<<ans<<endl;
    return 0;
}

