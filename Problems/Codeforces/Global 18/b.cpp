#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int getBits(int i,int r){
    int sz = 1<<(i+1);
    int x = r/sz;
    int ans = x*(sz/2);
    int mn = (x*sz)+(sz/2);
    if(r<mn)return ans;
    else return ans +((r-mn)+1);
}

signed main(){__
	int t= 1,n,l,r;
    cin>>t;
    while(t--){
        cin>>l>>r;
        n = (r-l)+1;
        int ans = 1e15;
        // cout<<getBits(0,8)<<" "<<getBits(0,1)<<endl;
        for(int i= 0 ;i<20;i++){
            int x = getBits(i,r)-getBits(i,l-1);
            ans = min(ans,n-x);
        }
        cout<<ans<<endl;
    }
    return 0;
}  
