#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> st;
    int mx = *max_element(nums.begin(),nums.end());
    for(int i = 0;i<n;i++){
        if(nums[i] == mx)continue;
        int j = i;
        while(j<n && nums[j]!= mx){ 
            if(!st.empty() && nums[j] == st.back())st.pop_back();
            else if(st.empty() || st.back()>nums[j])st.push_back(nums[j]);
            else return cout<<"No"<<endl,0;
            j++;
        }
        i = j;
        if(st.size())return cout<<"No"<<endl,0;
    }
    cout<<"Yes"<<endl;
    return 0;
}