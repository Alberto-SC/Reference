#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        int a = 0,b = 0;
        for(int i = 0;i<n-1;i++){
            if(s[i]== '1' && s[i+1]=='0')a++;
            else if(s[i]== '0' && s[i+1]=='1')b++;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int na  = a,nb = b;
            if(i){
                if(s[i-1]=='0' && s[i]=='0')nb++;
                if(s[i-1]=='0' && s[i]=='1')nb--;
                if(s[i-1]=='1' && s[i]=='0')na--;
                if(s[i-1]=='1' && s[i]=='1')na++;
            }
            if(i!=n-1){
                if(s[i]=='0' && s[i+1]=='0')na++;
                if(s[i]=='0' && s[i+1]=='1')nb--;
                if(s[i]=='1' && s[i+1]=='0')na--;
                if(s[i]=='1' && s[i+1]=='1')nb++;
            }
            if(na ==nb)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}