#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> ans(1000007);
int idx = 0;
void solve(int n,int gcd = 1){
    if(n==1){
        ans[idx++] = gcd;
        return ;
    }
    if(n == 2){
        ans[idx++] = gcd;
        ans[idx++] = gcd*2;
        return;
    }
    if(n == 3){
        ans[idx++] = gcd;
        ans[idx++] = gcd;
        ans[idx++] = gcd*3;
        return;
    }
    for(int i = 1;i<=n;i+=2)
        ans[idx++] = gcd;
    
    solve(n/2,gcd*2);
}

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        solve(n);
        for(int i = 0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  
