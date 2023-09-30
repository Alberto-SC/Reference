#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    cin>>k;
    multiset<int> st;
    for(int i = 0;i<k;i++){
        st.insert(nums[i]);
        
    }
    
    auto it = st.end();
    it--;
    cout<<*it<<" ";
    for(int i = 0;i<n-k;i++){
        st.erase(st.find(nums[i]));
        st.insert(nums[i+k]);
        it = st.end();
        it--;
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}