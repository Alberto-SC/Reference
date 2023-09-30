#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        int ans;
        for(int i = 0;i<=10000;i++){
            int need = 0;
            for(int j = 0;j<n;j++){
                int x = a[j]*i;
                if(b[j]>=x)continue;
                else need+=x-b[j];
            }
            if(need>k)break;
            ans = i;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
