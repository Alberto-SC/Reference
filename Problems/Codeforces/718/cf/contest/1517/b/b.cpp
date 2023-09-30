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
        vector<multiset<int>> nums(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int x;
                cin>>x;
                nums[i].insert(x);
            }
        }
        int ans = 0;
        vector<vector<int>> res(m,vector<int>(n));
        for(int i = 0;i<m;i++){
            int mn = 1e18;
            for(int j = 0;j<n;j++){
                mn = min(mn,*nums[j].begin());
            }
            ans+=mn;
            bool flag = true;
            for(int j = 0;j<n;j++){
                if(flag &&(*nums[j].begin())== mn){
                    nums[j].erase(nums[j].begin());
                    flag = false;
                    res[i][j] = mn;
                }

                else {
                    int mx = *nums[j].rbegin();
                    nums[j].erase(nums[j].find(mx));
                    res[i][j] = mx;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<res[j][i]<<" ";
            }
            cout<<endl;
        }
        // cout<<ans<<endl;
    }
    return 0;
}  
