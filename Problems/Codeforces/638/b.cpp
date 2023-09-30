#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> ans;
        vector<int> block(k);
        for(int i = 0;i<k;i++){block[i] = nums[i];ans.push_back(nums[i]);} 
        int who = 0;
        bool yes = true;
        for(int i = k;i<n;){
            bool flag = false;
            for(int j= 0;j<k;j++)if(block[j]== nums[i])flag = true;
            if(!flag){yes = false;break;}
            if(nums[i] == block[who])ans.push_back(nums[i++]);
            else ans.push_back(block[who]);
            who++;
            who%=k;
        }
        if(yes)for(auto c:ans)cout<<c<<" ";
        else cout<<-1;
        cout<<endl;
    }   
    return 0;
}