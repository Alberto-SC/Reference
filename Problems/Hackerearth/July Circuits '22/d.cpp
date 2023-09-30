
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

void LNDS(const vector<int>& arr,vector<int> &who,vector<int> &v) {
    vector<int> sub;
    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        if (sub.empty() || sub[sub.size() - 1] <= x) { 
            if(sub.size() && sub.back()==x)
                v[i] = 1;
            sub.push_back(x);
            who[i] = sub.size();
        } else {
            int idx = upper_bound(sub.begin(), sub.end(), x) - sub.begin();
            sub[idx] = x; 
            who[i] = idx+1;
            if(idx && sub[idx-1]==x)
                v[i] = 1;
        }
    }
}

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> pos[n+3];
        for(int i = 0;i<n;i++){
            pos[nums[i]].push_back(i);
        }

        vector<int> maxUPL(n);
        vector<int> maxUPR(n);
        vector<int> maxDWL(n);
        vector<int> maxDWR(n);
        vector<int> LEqual(n);
        vector<int> REqual(n);
        vector<int> d(n);
        int ans  = 0;
        LNDS(nums,maxUPL,LEqual);
        reverse(nums.begin(),nums.end());
        LNDS(nums,maxUPR,REqual);
        reverse(maxUPR.begin(),maxUPR.end());
        reverse(nums.begin(),nums.end());

        for(int i= 0;i<n;i++)nums[i]*=-1;
        LNDS(nums,maxDWL,d);
        reverse(nums.begin(),nums.end());
        LNDS(nums,maxDWR,d);
        reverse(maxDWR.begin(),maxDWR.end());
        reverse(nums.begin(),nums.end());

        // for(auto c:LEqual)cout<<c<<" ";
        // cout<<endl;
        // for(auto c:REqual)cout<<c<<" ";
        // cout<<endl;

        vector<int> nextEqual(n);
        for(int i = 0;i<n;i++)
            if(REqual[i])
                nextEqual.push_back(i);
        

        for(int i = 0;i<n;i++){
            nums[i]*=-1;
            ans = max(ans,maxUPL[i]);
            ans = max(ans,maxDWL[i]);
            int nxt = upper_bound(pos[nums[i]].begin(),pos[nums[i]].end(),i)-pos[nums[i]].begin();
            int me = lower_bound(pos[nums[i]].begin(),pos[nums[i]].end(),i)-pos[nums[i]].begin();
                
            if(nxt != pos[nums[i]].size()){
                ans = max(ans,maxUPL[i]+maxUPR[pos[nums[i]][nxt]]);
                ans = max(ans,maxDWL[i]+maxDWR[pos[nums[i]][nxt]]);
            }                

            int idx = upper_bound(nextEqual.begin(),nextEqual.end(),i)-nextEqual.begin();
            if(LEqual[i] &&  idx != nextEqual.size()){
                ans = max(ans,maxUPL[i]+max(maxUPR[nextEqual[idx]],maxDWR[nextEqual[idx]]));
                ans = max(ans,maxDWL[i]+max(maxUPR[nextEqual[idx]],maxDWR[nextEqual[idx]]));
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}  


// 10 7 4 4 4 8 8 3 2 