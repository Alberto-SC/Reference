#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 1000007;
int main(){__
    freopen("deposits.in","r",stdin);
    freopen("deposits.out","w",stdout);
    int n,m,c;
    cin>>n;
    vector<int> a(n);
    for(auto &c:a)cin>>c;
    cin>>m;
    vector<int> bk(maxn);
    for(int i = 0;i<m;i++){
        cin>>c;
        bk[c]++;
    }
    lli ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 1;j*j<=a[i];j++){
            if(a[i]%j == 0)ans+=bk[j];
            if(a[i]%j == 0 && a[i]/j != j)ans+=bk[a[i]/j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}