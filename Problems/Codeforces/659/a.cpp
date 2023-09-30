#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int mx = -1;
        for(auto &c:nums)cin>>c,mx = max(c,mx);
        vector<string>ans(n+1,string(mx+1,'z'));
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<nums[i-1];j++){
                ans[i][j] = ans[i-1][j];
            }   
            for(int j = nums[i-1];j<=mx;j++){
                if(ans[i-1][j] == 'a')
                    ans[i][j] ='z';
                else 
                    ans[i][j] ='a';
            }
        }
        // cout<<ans[0].size()<<endl;
        for(auto c:ans)cout<<c<<endl;
        // cout<<endl;
    }
    return 0;
}