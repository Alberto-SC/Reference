#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    set<int> st(nums.begin(),nums.end());
    cout<<st.size()<<endl;
    return 0;
}