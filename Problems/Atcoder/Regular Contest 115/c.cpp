#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);



signed main(){__
	int t= 1,n;
    cin>>n;
    vector<int> ans(n+1);
    ans[n] = 1;
    for(int i = n;i>=1;i--){
        if(2*i<=n)
            ans[i] = ans[2*i]+1;
        else 
            ans[i] = 1;
    }
    for(int i = 1;i<=n;i++)
        cout<<ans[i]<<" ";


    for(int i = 1;i<=n;i++){
        for(int j = 2;j<=n;j++){
            if(i*j>n)break;
            assert(ans[i]!= ans[i*j]);
        }
    }
    cout<<endl;
    return 0;
}  
