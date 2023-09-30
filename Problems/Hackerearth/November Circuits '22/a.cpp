#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n);
        for(auto &c:a)cin>>c;
        vector<int> b(n);
        for(auto &c:b)cin>>c;
        vector<int> cont(32);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<32;j++){
                if((a[i]>>j)&1)cont[j]++;
                if((b[i]>>j)&1)cont[j]++;
            }
        }
        int ans = 0;
        for(int i = 0;i<32;i++){
            if(cont[i]==2*n)ans|=(1<<i);
        }
        cout<<ans<<endl;
    }
    return 0;
}