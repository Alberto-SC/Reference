#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,c&=1;
    vector<int> st;
    for(int i = 0;i<n;i++){
        if(st.size() && nums[i] == st.back())st.pop_back();
        else st.push_back(nums[i]);
    }
    cout<<"No\0Yes\0"+(3*(st.size()<=1))<<endl;

    return 0;
}