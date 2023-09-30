#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool solve(vector<int> nums){
    int n = nums.size();
    vector<int> pref(n);
    vector<int> pos;
    for(int i = 0;i<n;i++){
        if(nums[i]==0)pos.push_back(i);
        pref[i] = nums[i]+(i?pref[i-1]:0);
    }
    map<int,int> mp;
    mp[pref[0]] =0;
    bool flag = false;
    for(int i = 1;i<n;i++){
        if(pref[i]== 0 || pref[i]==1){
            int idx = lower_bound(pos.begin(),pos.end(),0)-pos.begin();
            if(idx<pos.size() && pos[idx]<=i)flag = true;
            if(!mp.count(pref[i]))
                mp[pref[i]] = i;
            continue;
        }
        if(pref[i]<0){
            int idx = lower_bound(pos.begin(),pos.end(),0)-pos.begin();
            int idx2 = upper_bound(pos.begin(),pos.end(),i)-pos.begin();
            if(idx<pos.size() && pos[idx]<=i && idx2-idx>abs(pref[i]))flag = true;
        }
        if(pref[i]>1){
            int idx = lower_bound(pos.begin(),pos.end(),0)-pos.begin();
            int idx2 = upper_bound(pos.begin(),pos.end(),i)-pos.begin();
            if(idx<pos.size() && pos[idx]<=i && idx2-idx>=pref[i])flag = true;
        }
        int need = pref[i]-1;
        int need2 = pref[i];
        int need3 = pref[i]+1;
        if(mp.count(need)){
            int idx = lower_bound(pos.begin(),pos.end(),mp[need]+1)-pos.begin();
            if(idx<pos.size() && pos[idx]<=i && mp[need]+1!= i)flag = true;
        }
        if(mp.count(need2)){
            int idx = lower_bound(pos.begin(),pos.end(),mp[need2]+1)-pos.begin();
            if(idx<pos.size() && pos[idx]<=i && mp[need2]+1!=i)flag = true;
        }
        if(mp.count(need3)){
            int idx = lower_bound(pos.begin(),pos.end(),mp[need3]+1)-pos.begin();
            int idx2 = upper_bound(pos.begin(),pos.end(),i)-pos.begin();
            if(idx<pos.size() && pos[idx]<=i && mp[need3]+1!= i && idx2-idx>1)flag = true;
        }

        if(!mp.count(pref[i]))
            mp[pref[i]] = i;
    }    
    return flag;
}

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;nvb 
        vector<int> nums(n);
        for(auto &c:nums){
            cin>>c;
            if(c<k)c = -1;
            else if(c>k)c = 1;
            else c = 0;
        }
        bool flag = false;
        flag|= solve(nums);
        reverse(nums.begin(),nums.end());
        flag|= solve(nums);
        if(n==1&& nums[0]==0)flag = true;
        // for(auto c:pref)cout<<c<<" ";
        // cout<<endl;
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}  
