#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m;
    cin>>n>>m;
    vector<lli> a(n);
    vector<lli> b(m);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    lli gcd = 0;
    for(int i = 1;i<n;i++)
        gcd = __gcd(gcd,abs(a[i]-a[0]));
    for(int i = 0;i<m;i++){
        cout<<__gcd(gcd,a[0]+b[i])<<" ";
    }
    cout<<endl;
    return 0;   
}  

