#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
 
// Find a subset of a vector of integers such that sum%M is i for all i<=M

signed main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c,c%=m;
        sort(nums.begin(),nums.end());
        vector<bool> DP(m+1);
        vector<int> a(m+1);
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            int l = i;
            while(l<n && nums[i]== nums[l]){
                l++;
            }
            a.assign(m+1,0);
            int x = nums[i];
            int last = 0;
            for(int j = 0;j<min(m,l-i);j++){
                if(!DP[x%m])
                    a[x%m]=a[last%m]+1;
                DP[x%m] = true;
                last = x;
                x+=nums[i];
            }
            
            for(int j = 0;j<=m;j++){
                int nw = (((j-nums[i])%m)+m)%m;
                if(!DP[j]&& DP[nw] && a[nw]<l-i){
                    a[j] = a[nw]+1;
                    DP[j] = true;
                }
            }
 
            i = l-1;
        }
        cout<<(DP[0]||DP[m]?"YES":"NO")<<endl;
    }
    return 0;
}  