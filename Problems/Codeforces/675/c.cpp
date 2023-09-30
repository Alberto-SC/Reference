#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;

int main(){__
    int t = 1,n;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        lli ans = 0;
        lli pot = 1; 
        lli other = 0;
        for(int i = n-1;i>=0;i--){
            lli f = n-(n-1-i)-1;
            lli d = n-1-i; 
            lli subs = (f*(f+1))/2;
            lli one = (((s[i]-'0')*subs)%mod)*pot;
            one%=mod;  
            (ans+=one)%=mod;
            one = (s[i]-'0')*other;
            one%=mod;
            (ans+=one)%=mod;
            other+= ((d+1)*pot);
            (pot*=10)%=mod;
            other%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}

