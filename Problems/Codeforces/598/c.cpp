#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,d;
    cin>>n>>m>>d;
    vector<int> nums(m);
    for(auto &c:nums)cin>>c;
    vector<int> ans(n,0);
    int next = n-accumulate(nums.begin(),nums.end(),0);
    for(int i = 0;i<next;i++)
        ans[i] = 0;
    int i = next,ind = 0;
    while(i<n){
        for(int j = 0;j<nums[ind];j++)
            ans[i+j] = ind+1;
        i+=nums[ind];
        ind++;
    }
    int here = 0,flag = false;
    next++;
    for(int i = 0;i<m;i++){
        // cout<<here<<" "<<next<<endl;
        if(d<(next-here)){
            for(int j= 0;j<nums[i];j++)
                ans[here+((d-1)+j)] =(i+1);
            for(int j =here+(d-1)+nums[i];j<next+(nums[i]-1);j++)
                ans[j] = 0;
            here += (d+nums[i])-1;
            next+=nums[i];
        }
        else{
            flag = true;
            break;              
        }
        // for(auto c:ans)cout<<c<<" ";
            // cout<<endl;
    }
    if(n-here<d)flag = true;
    if(flag){
        cout<<"YES"<<endl;
        for(auto c:ans)cout<<c<<" ";
            cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}