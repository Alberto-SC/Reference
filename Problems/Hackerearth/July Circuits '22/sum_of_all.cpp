#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

int powMod(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
	int t= 1,n;
    cin>>t;
    vector<int> potTen(100007);
    potTen[0] = 1;
    for(int i = 1;i<n;i++){
        potTen[i] = (potTen[i-1]+ ((powMod(10,i)*powMod(2,i))%mod) )%mod;
    }   

    for(int i = 0;i<n;i++)
        cout<<potTen[i]<<" ";
    cout<<endl;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int digit = s[i]-'0';
            int x  = powMod(2,i)*digit;
            x%=mod;
            x*=potTen[n-1-i];
            x%=mod;
            (ans+=x)%=mod;
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}  
