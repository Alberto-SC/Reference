#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    bool flag = true;
    vector<int> left(n,1);
    vector<int> rigth(n,1);
    for(int i = 1;i<n;i++){
        if(nums[i]<nums[i-1])
            left[i]= left[i-1]+1;
    }
    for(int i = n-2;i>=0;i--){
        if(nums[i]<nums[i+1])
            rigth[i] =rigth[i+1]+1;
    }
    for(auto c:nums)cout<<setw(2)<<c<<" ";
    cout<<endl;
    for(auto c:left)cout<<setw(2)<<c<<" ";
    cout<<endl;
    for(auto c:rigth)cout<<setw(2)<<c<<" ";
    cout<<endl;
    stack<pair<int,int>> s;
    vector<int> fleft(n,-1);
    vector<int> frigth(n,-1);
    for(int i = 0;i<n;i++){
        while(!s.empty() && s.top().first<nums[i]){
            pair<int,int> num = s.top();
            s.pop();
            frigth[num.second] = i;
        }
        s.push({nums[i],i});
    }
    for(int i = n-1;i>=0;i--){
        while(!s.empty() && s.top().first<nums[i]){
            pair<int,int> num = s.top();
            s.pop();
            fleft[num.second] = i;
        }
        s.push({nums[i],i});
    }
    for(auto c:frigth)cout<<setw(2)<<c<<" ";
    cout<<endl;
    for(auto c:fleft)cout<<setw(2)<<c<<" ";
    cout<<endl;
    vector<int> ans(n);
    for(int i = 0;i<n;i++){
        if(fleft[i]!=-1)
            ans[i]+=left[fleft[i]];
        if(frigth[i]!=-1)
            ans[i]+=rigth[frigth[i]];
    }
    for(auto c:ans)cout<<setw(2)<<c<<" ";
    cout<<endl;
    return 0;
}  
