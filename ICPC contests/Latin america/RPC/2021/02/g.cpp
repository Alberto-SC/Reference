#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n,m,a,c,x0;
    while(t--){
        cin>>n>>m>>a>>c>>x0;
        vector<int> nums(n);
        for(int i = 0;i<n;i++){
            nums[i] = ((a*x0)+c)%m;
            x0 = nums[i];
        }
        
        int cont = 0;
        // for(auto c:nums)cout<<c<<" ";
        // cout<<endl;
        for(int i= 0;i<n;i++){
            int x = nums[i];
            int l = 0,r = n-1;
            while(l<=r){
                int mid = (l+r)>>1;
                if(nums[mid]==x){
                    cont++;
                    break;
                }
                if(nums[mid]<x)l = mid+1;
                else r = mid-1;
            }
        }
        cout<<cont<<endl;

    }
    return 0;
}  
