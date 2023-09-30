#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
vector<int> facts[2000007];
vector<int> p(2000007);
vector<bool> used(2000007);

bool check(int x){
    for(auto c:facts[x]){
        if(used[c])return false;
    }
    return true;
}

int main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for (int i=2;i<2000005;i++){
        if (!p[i]){
            for (int x=i;x<2000005;x+=i){
                facts[x].push_back(i);  
                p[x]=1;
            }
        }
    }
    vector<int> ans(n);
    bool F = false;
    int l = 2;
    for(int i = 0;i<n;i++){
        if(F){  
            while(!check(l))l++;
            for(auto c:facts[l])
                used[c] = true;
            ans[i] = l; 
        }
        else{
            if(check(nums[i])){
                ans[i] = nums[i];
                for(auto c:facts[nums[i]])
                    used[c] = true;
            }
            else{
                int l2 = nums[i]+1;
                while(!check(l2))l2++;
                ans[i] = l2;
                for(auto c:facts[l2])
                    used[c] = true;
                F = true;
            }
        }
    }   
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}