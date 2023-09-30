#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> f(n);
        vector<int> c(n);
        for(auto &c:f)cin>>c;
        for(auto &d:c)cin>>d;
        lli idx,mn = 1e9+7;
        for(int i = 0;i<n;i++){
            if(c[i]<mn && c[i]!= 0){
                idx = i;
            }
        }
        lli m = 0,ans = 0;
        while(m <n){
            lli mn = 1e15;
            int idx2;
            for(int i= idx+1;i<idx+f[idx];i++){
                if((i-idx)*c[idx]+c[i+1]){
                    idx2 = i;
                    mn = min(mn,(i-idx)*c[idx]+c[i%n]);
                }
            }
            m+= idx2-idx;
            ans += mn;
            if(m>=n)
                ans-=c[idx2%n];
            idx = idx2+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}  

