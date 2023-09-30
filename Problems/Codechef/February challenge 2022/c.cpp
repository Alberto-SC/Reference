#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c,c&=1;
        vector<int> nums2 =nums;
        int idxOne = -1,idxZero =-1;
        for(int i = 0;i<n;i++){
            if(nums[i])idxOne = i;
            else idxZero = i;
        }
        if(idxOne==-1){cout<<-1<<endl;continue;}
        vector<pair<int,int>> ans;
        vector<pair<int,int>> ans2;
        if(idxZero==-1){
            ans.push_back({1,2}),nums[0] = 0;
            ans2.push_back({2,1}),nums2[1] = 0;
        }
        else{
            if(nums[0]){
                if(idxOne==0){
                    ans.push_back({2,1});
                    ans.push_back({1,2});
                }
                else{
                    ans.push_back({1,idxOne+1});
                }
                nums[0] = 0;
            }
            if(nums2[1]){
                if(idxOne==1){
                    ans2.push_back({1,2});
                    ans2.push_back({2,1});
                }
                else 
                    ans2.push_back({2,idxOne+1});
                nums2[1] = 0;
            } 
        }
        if(!nums[1]){
            ans.push_back({2,idxOne+1});
            nums[1] = 1;
        }
        if(!nums2[0]){
            ans2.push_back({1,idxOne+1});
            nums2[0] = 1;
        }
        for(int i = 2;i<n;i++){
            if(i&1 &&  !nums[i])
                ans.push_back({i+1,2}),nums[i] = 1;   
            if(i&1 && nums2[i])
                ans2.push_back({i+1,1}),nums2[i] =0;
            if((i%2)==0 && nums[i])
                ans.push_back({i+1,2}),nums[i] = 0;
            if((i%2)==0 && !nums2[i])
                ans2.push_back({i+1,1}),nums2[i] = 1;
        }
        if(ans.size()<ans2.size()){
            cout<<ans.size()<<endl;
            for(auto c:ans){
                cout<<c.first<<" "<<c.second<<endl;
            }
        }
        else{
            cout<<ans2.size()<<endl;
            for(auto c:ans2){
                cout<<c.first<<" "<<c.second<<endl;
            }
        }
    }
    return 0;
}