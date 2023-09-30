#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


signed main(){__
    int n;
    cin>>n;
    int mn = 1e16;
    pair<int,int> ans;
    for(int i = 1;i*i<=n;i++){
        if(n%i ==0){
            if((n/i)-i<mn){
                mn = (n/i)-i;
                ans = {i,n/i};
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}   