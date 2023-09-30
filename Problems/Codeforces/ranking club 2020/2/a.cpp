#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int mod = 1000000007; 
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(auto &c:a)cin>>c;
    lli ans = 1;
    for(int i = 0;i<m;i++){
        set<char> how;
        for(int j = 0;j<n;j++)
            how.insert(a[j][i]);
        
        ans=((ans%mod)*(how.size()%mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}