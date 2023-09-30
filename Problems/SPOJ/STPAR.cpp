#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0)break;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int last = 1;
        stack<int> st;
        for(int i =0;i<n;i++){
            if(nums[i]!= last){
                if(!st.empty() && st.top()==last){
                    last++;
                    i--;
                    st.pop();
                }
                else
                    st.push(nums[i]);
            }
            else
                last++;
        }
        bool f = true;
        while(!st.empty()){
            if(st.top()!=last)
                f = false;
            st.pop();
            last++;
        }
        if(f)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}