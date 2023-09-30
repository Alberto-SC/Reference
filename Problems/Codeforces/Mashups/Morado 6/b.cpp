#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){
    int t = 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c,c--;
        vector<int> pos(n);
        for(int i = 0;i<n;i++)
            pos[nums[i]] = i;
        vector<pair<int,int>> ans;
        for(int i = 0;i<n;i++){
            if(pos[i]==i)continue;
            if(i== 0){
                if(pos[i]<n/2){
                    ans.push_back({pos[i]+1,n});
                    ans.push_back({n,1});
                    ans.push_back({pos[i]+1,n});
                    pos[nums[i]] = pos[i];
                    swap(nums[i],nums[pos[i]]);
                }
                else{
                    ans.push_back({pos[i]+1,1});
                    pos[nums[i]] = pos[i];
                    swap(nums[i],nums[pos[i]]);
                }   
            }
            else{
                if(i <n/2 && pos[i]<n/2){
                    ans.push_back({pos[i]+1,n});
                    ans.push_back({n,i+1});
                    ans.push_back({pos[i]+1,n});
                    pos[nums[i]] = pos[i];
                    swap(nums[i],nums[pos[i]]);
                }
                else if(i<n/2 && pos[i]>=n/2){
                    ans.push_back({pos[i]+1,1});
                    ans.push_back({1,n});
                    ans.push_back({n,i+1});
                    ans.push_back({1,n});
                    ans.push_back({1,pos[i]+1});
                    pos[nums[i]] = pos[i];
                    swap(nums[i],nums[pos[i]]);
                }
                else {
                    ans.push_back({pos[i]+1,1});
                    ans.push_back({1,i+1});
                    ans.push_back({pos[i]+1,1});
                    pos[nums[i]] = pos[i];
                    swap(nums[i],nums[pos[i]]);
                    
                }
            }
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
    }
}