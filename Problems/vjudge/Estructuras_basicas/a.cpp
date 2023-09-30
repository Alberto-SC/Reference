#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,key= 0;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    map<int,int> m,m2;
    for(int i = 0;i<n;i++)
        if(m.find(nums[i]) == m.end()) m[nums[i]] = key,m2[key++] = nums[i];
    vector<bool> used(key);
    list<int> disp;
    for(int i = 0;i<n;i++){
        if(!used[m[nums[i]]]){
            if(disp.size()== k){
                used[disp.front()] = false;
                disp.pop_front();
                disp.push_back(m[nums[i]]);
                used[m[nums[i]]] = true;
            }
            else{
                disp.push_back(m[nums[i]]);
                used[m[nums[i]]] = true;
            }
        }
    }
    cout<<disp.size()<<endl;
    reverse(disp.begin(),disp.end());
    for(auto c:disp)cout<<m2[c]<<" ";
    return cout<<endl,0;
}