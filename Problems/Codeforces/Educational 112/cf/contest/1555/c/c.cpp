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
        vector<int> ac1(n);
        vector<int> ac2(n);
        for(auto &c:ac1)cin>>c;
        for(auto &c:ac2)cin>>c;
        for(int i= 1;i<n;i++){
            ac1[i] = ac1[i-1]+ac1[i];
            ac2[i] = ac2[i-1]+ac2[i];
        }
        int ans = 1e16;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        for(int i = 0;i<n;i++){
            if(i==0)ans = min(ac1[n-1]-ac1[0],ans);
            else if(i ==n-1)ans = min(ac2[n-2],ans);
            else ans = min(max(ac1[n-1]-ac1[i],ac2[i-1]),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
