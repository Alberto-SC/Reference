#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        map<pair<int,int>,int> mp;
        int a = 0,b = 0;
        for(int i = 0;i<n;i++){
            a+=s[i]=='D';
            b+=s[i]=='K';
            int g = __gcd(a,b);
            cout<<(++mp[{a/g,b/g}])<<" ";
        }
        cout<<endl;
    }
    return 0;
}  
