#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int n,x;
    cin>>n;
    vector<int> p(n);
    for(auto &c:p)cin>>c;
    vector<int> A(n),B(n);
    vector<int> r(n+1);
    for(int i = 0;i<n;i++)
        r[p[i]] = i+1;
    for(int i = 1;i<=n;i++){
        A[i-1] = 30000*i;
        B[i-1] = 30000*(n-i)+ r[i];
    }
    for(auto c:A)cout<<c<<" ";
    cout<<endl;
    for(auto c:B)cout<<c<<" ";
    cout<<endl;
}