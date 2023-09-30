#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        vector<int> l(n);
        vector<int> r(n);
        for(auto &c:nums)cin>>c;
        vector<int> zeros;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0)zeros.push_back(i);
            if(nums[i]==1){
                l[i] = 1+(i?l[i-1]:0);
            }
            else    
                l[i] = 0;    
            ans = max(ans,l[i]);
        }
        for(int i = n-1;i>=0;i--){
            if(nums[i]== 0)r[i] = 0;
            else 
                r[i] = 1+(i==n-1?0:r[i+1]);
        }
        if(k>=zeros.size()){
            cout<<n<<endl;
            for(int i = 0;i<n;i++)
                cout<<1<<" ";
            cout<<endl;
            continue;
        }
        if(k==0){
            cout<<ans<<endl;
            for(int i = 0;i<n;i++)
                cout<<nums[i]<<" ";
            cout<<endl;
            continue;
        }
        int il = 0,ir = k-1,idl,idr;
        while(ir<zeros.size()){
            int nw = (zeros[ir]-zeros[il])+1;
            nw += zeros[il]?l[zeros[il]-1]:0;
            nw += zeros[ir]==n-1?0:r[zeros[ir]+1];
            // cout<<nw<<endl;
            if(nw>ans){
                ans = max(ans,nw);
                idl = il;
                idr = ir;
            }
            il++,
            ir++;
        }
        for(int i = zeros[idl];i<=zeros[idr];i++){
            if(nums[i]== 0)nums[i] = 1;
        }
        cout<<ans<<endl;
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
        
    }
    return 0;
}  
