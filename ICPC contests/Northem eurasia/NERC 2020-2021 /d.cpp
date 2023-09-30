#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>b;
        vector<int> nums(m);
        for(auto &c:nums)cin>>c;
        sort(nums.rbegin(),nums.rend());
        int ans = 0;
        if(a<b){
            int x = b-a;
            int idx = 0;
            for(int i = 1;i<x;i++){
                // cout<<i<<endl;
                while(idx<m && nums[idx]+i>=b){
                    idx++;
                }
                if(idx<m  && nums[idx]+i<b)ans++,idx++;
                if(idx>=m)break;
            }
        }
        else{
            int x = a-b;
            int idx = 0;
            for(int i = 1;i<x;i++){
                while(idx<m && nums[idx]+i>n-b){
                    idx++;
                }
                if(idx<m && nums[idx]+i<=n-b)ans++,idx++;
                if(idx>=m)break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

