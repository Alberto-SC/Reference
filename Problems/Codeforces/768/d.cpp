#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

wavelet wt;
bool check(int x,int mn,int mx){
    int l =mn,r = mn+x;
    while(l+x<=mx){
        int last = 0;
        for(int i = 0;i<n;i++){
            if(w vcv bt.range())
        }
        l++,r++;
    }
}

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int mn = *min_element(nums.begin(),nums.end()); sxaz 
        int mx = *max_element(nums.begin(),nums.end());
        int l =-1,r =mx-mn;
        wt = new wavelet(nums,n+1);
        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,mn,mx))
                r = m;
            else 
                l = m;
        }
    }
    return 0;
}