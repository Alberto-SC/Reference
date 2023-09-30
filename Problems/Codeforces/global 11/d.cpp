#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> reverse(vector<int> &nums,vector<int> d){
    vector<int> res;
    int z = 0,n = nums.size();
    for(int i = d.size()-1;i>=0;i--){
        z+=d[i];
        for(int k = n-z,c = 0;c<d[i];c++,k++){
            res.push_back(nums[k]);
        }
    }  
    return res;
}

int main(){__
    int t = 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> copy;
    copy = nums;
    sort(copy.begin(),copy.end());
    vector<vector<int>> res;
    int ans = 0;
    while(nums!= copy){ 
        vector<int> pos(n+1);
        for(int i = 0;i<n;i++){
            pos[nums[i]] = i;
        }
        vector<int> d;
        for(int i = 0;i<n;i++){
            if(nums[i]!= n && pos[nums[i]+1]<i){
                if(pos[nums[i]+1])d.push_back(pos[nums[i]+1]);
                int zz = pos[nums[i]+1];
                while(zz+1<n && nums[zz+1] == nums[zz]+1){zz++;}
                d.push_back((zz-pos[nums[i]+1])+1);
                d.push_back(i-zz);
                if(i<n-1)d.push_back(n-(i+1));
                break;
            }
        }
        res.push_back(d);
        nums = reverse(nums,d);
        ans++;
    }
    cout<<ans<<endl;
    for(auto c:res){
        cout<<c.size()<<" ";
        for(auto d:c)cout<<d<<" ";
        cout<<endl;
    }
    return 0;
}

