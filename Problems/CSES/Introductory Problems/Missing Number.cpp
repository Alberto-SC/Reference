#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int n;
    int ans = 0;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int x;cin>>x;
        ans+=x;
    }
    cout<<((n*(n+1))/2)-ans<<endl;
    return 0;
}