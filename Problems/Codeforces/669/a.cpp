#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ans;
        int sum = 0;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(flag){
                if(i&1)sum+=nums[i];
                else sum-=nums[i];
            }
            else {
                if(i&1)sum-=nums[i];
                else sum+=nums[i];
            }
            // cout<<i<<" "<<sum<<endl;
            if(abs(sum)== 2){
                ans.pop_back();
                ans.push_back(nums[i]);
                sum = 0;                
                flag = ! flag;
            }
            else ans.push_back(nums[i]);
        }
        if(sum!= 0){
            int idx ;
            for(int i = ans.size()-1;i>=0;i--)
                if(ans[i]==1){idx = i;break;}
            cout<<ans.size()-1<<endl;
            for(int i = 0;i<ans.size();i++)
                if(i!= idx)cout<<ans[i]<<" ";
            cout<<endl;
        }
        else {
            cout<<ans.size()<<endl;
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }

    }
    return 0;
}

