#include <bits/stdc++.h>
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;

int get(int x){
    int ans = 0;
    while(x){
        ans++;
        x/=2;
    }
    return ans;
}
        
signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        int ans = n+1;
        for(int c = 0;c<26;c++){
            int cnt = 0;
            int res = 0;
            for(int i = 0;i<n;i++){
                if((s[i]-'a') == c){
                    res = max(res,get(cnt));
                    cnt = 0;
                }
                else cnt++;
            }
            res=max(res,get(cnt));
            ans = min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;    
}
