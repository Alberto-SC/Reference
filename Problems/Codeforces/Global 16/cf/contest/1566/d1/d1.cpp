#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int ans = 0;
        vector<vector<int>> nums(n,vector<int>(m));
        for(int i = 0;i<n;i++)
            for(auto &c:nums[i])cin>>c;
        for(int k = 0;k<n;k++){
            for(int i = 0;i<m;i++){
                int x = 0;
                for(int j = 0;j<i;j++){
                    if(nums[k][j]<nums[k][i])x++;
                }
                ans+=x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
