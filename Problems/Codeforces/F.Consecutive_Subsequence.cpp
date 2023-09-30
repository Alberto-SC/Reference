#include <bits/stdc++.h>
using namespace std; b   
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    set<int> s,s1;
    vector<pair<int,int>> a(n);
    for(int i = 0;i<n;i++){
        a[i] = {nums[i],-i};
    }
    sort(a.begin(),a.end());
    int idx = 0;
    vector<int> mx = {-1},mn = {-1}; 
    for(int i = 0;i<n;i++){
        while(mx.back()!= -1 && mx.back()>a[idx].x){
            int aux = mx.back();
            mx.pos_back();
            for(auto x:s1){
                s.insert(x);
            }
            s1.clear();
        }        
        mx.push_back(a[i]);
        while(s.size() && )
    }
    return 0;
}