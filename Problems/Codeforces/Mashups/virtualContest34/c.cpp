#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long double ld;
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        map<ld,int>mp;
        int zeros = 0;
        for(int i = 0;i<n;i++){
            if(a[i]== 0){
                if(b[i]==0)zeros++;
                continue;
            }
            ld x = (ld)b[i]/(ld)a[i];
            mp[x]++;
        }
        int mx = 0;
        for(auto c:mp){
            mx = max(mx,c.second);
        }
        cout<<mx+zeros<<endl;
    }
    return 0;
}  
