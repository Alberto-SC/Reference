#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n,t,s;
int solve(vector<int> nums){
    vector<pair<int,int>> neg;
    vector<pair<int,int>> pos;
    t = s/n;
    int l = -1,r = -1,mx = 0;
    bool fneg = false;
    for(int i = 0;i<3*n;i++){
        if(nums[i]-t<0){
            neg.push_back({nums[i]-t,i});
            if(l!=-1 && !fneg){
                r = neg.size()-1;
                fneg = true;
            }
        }
        else{
            pos.push_back({nums[i]-t,i});
            if(pos.back().first>mx)
                mx = pos.back().first,l = pos.size()-1,fneg = false;
        } 
    }
    int zeros = 0;
    int ans = 0;
    vector<bool> used(n,false);
    vector<int> falten(n);
    int cy = pos.size()/3;
    if(l==-1 || r==-1)return 0;
    while(cy--){
        while(pos[l].first){
            while((r<(int)neg.size() && neg[r].second<pos[l].second) ||used[neg[r].second%n]){
                r++;
            }
            if(r>=(int)neg.size())break;
            int rest = min(pos[l].first,abs(neg[r].first));
            ans+= rest*(neg[r].second-pos[l].second);
            neg[r].first+=rest;
            pos[l].first-=rest;
            if(!neg[r].first){
                zeros++;
                used[neg[r].second%n]=true;
                r++;
            }
        }
        zeros++;
        l++;
    }
    return ans;
}

signed main(){__
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,s+=c;
    for(int i = 0;i<n;i++)
        nums.push_back(nums[i]);
    for(int i = 0;i<n;i++)
        nums.push_back(nums[i]);

    int ans = solve(nums);
    nums.resize(n);
    reverse(nums.begin(),nums.end());
    for(int i = 0;i<n;i++)
        nums.push_back(nums[i]);
    for(int i = 0;i<n;i++)
        nums.push_back(nums[i]);
    ans = min(ans,solve(nums));
    cout<<ans<<endl;
    return 0;
}  
