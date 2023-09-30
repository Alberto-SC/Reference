#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy =nums;
        vector<int> u;
        sort(copy.begin(),copy.end());
        vector<set<int>> mp(n);
        int last = copy[0];
        u.push_back(last);
        for(int i = 0;i<n;i++){
            if(copy[i]!= last){
                last = copy[i];
                u.push_back(last);
            }
        }
        for(int i = 0;i<n;i++){
            nums[i] = lower_bound(u.begin(),u.end(),nums[i])-u.begin();
            copy[i] = lower_bound(u.begin(),u.end(),copy[i])-u.begin();
        }
        

        if(x>=n){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i = 0;i<n;i++){
            mp[nums[i]].insert(i);
        }
    
        for(int i = 0;i<n;i++){
            if(copy[i]==nums[i])continue;
            int position =*mp[copy[i]].begin();
            if(position-i>=x){
                mp[nums[i]].erase(i);
                mp[nums[i]].insert(position);
                mp[copy[i]].erase(mp[copy[i]].begin());
                swap(nums[i],nums[position]);
            }
            else if((n-i)-position>=x){
                mp[nums[n-1]].erase(n-1);
                mp[nums[n-1]].insert(position);
                swap(nums[n-1],nums[position]);
                mp[nums[i]].erase(i);
                mp[nums[i]].insert(n-1);
                mp[copy[i]].erase(mp[copy[i]].begin());
                swap(nums[n-1],nums[i]);
            }
            else if(position>=x && i>=x){
                swap(nums[0],nums[position]);
                mp[nums[i]].erase(i);
                mp[nums[i]].insert(position);
                mp[copy[i]].erase(mp[copy[i]].begin());
                swap(nums[0],nums[i]);
                swap(nums[0],nums[position]);
            }
            else break;
        }
        if(nums==copy)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
