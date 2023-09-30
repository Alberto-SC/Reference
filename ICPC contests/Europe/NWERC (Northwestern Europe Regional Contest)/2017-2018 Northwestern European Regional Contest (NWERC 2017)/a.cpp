#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 1000007;
vector<int> bit(maxn);
void add(int idx,int val){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=val;
}
int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}
int sum(int l,int r){
    return sum(r)-sum(l-1);
}
int main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        int last = copy[0];
        vector<int> U;
        U.push_back(last);
        for(int i = 0;i<n;i++){
            if(copy[i]!= last){
                last = copy[i];
                U.push_back(last);
            }
        }
        for(int i = 0;i<n;i++)
            nums[i]  = lower_bound(U.begin(),U.end(),nums[i])-U.begin();
        last = nums[n-1];
        vector<int> szR(n,1);
        vector<int> equalR(n,1);
        vector<int> limR(n);
        for(int i = n-2;i>=0;i--){
            if(nums[i+1]>=nums[i]){
                szR[i] = szR[i+1]+1;
                limR[i] = last;
            }
            else{
                last = nums[i];
                limR[i] = last;
            }
            if(nums[i+1]==nums[i])
                equalR[i] =equalR[i+1]+1;
        }
        for(int i = 0;i<n;i++)
            add(nums[i],1);
        map<int,ordered_set> mp;
        int ans = 0;
        int mx = *max_element(nums.begin(),nums.end());
        for(int i = 0;i<n-1;i++){
            if(nums[i]== nums[i+1]){
                add(nums[i],-1);
                continue;
            }
            if(nums[i]>nums[i+1]){
                ans++;
                add(nums[i],-1);
            }
            else if(nums[i]<=nums[i+1]){
                if(mp.count(nums[i])){
                    int j =  i+szR[i]-1;
                    int l = i,r = j;
                    while(l+1<r){
                        int m = (l+r)>>1;
                        if(mp[nums[i]].order_of_key(nums[m])<mp[nums[i]].size())
                            l = m;
                        else 
                            r = m;
                    }
                    j = i+(l-i);
                    for(int k = i;k<=j;k++)
                        add(nums[k],-1);
                    i = j;
                    mp[nums[i]].erase(nums[l]);
                    if(mp[nums[i]].size() == 0)
                        mp.erase(nums[i]);  

                    ans++;
                }
                else{
                    if(sum(nums[i],nums[i+1])-(equalR[i+1]+1)>1){
                        ans++;
                        add(nums[i],-1);
                        mp[nums[i]].insert(nums[i+1]);
                    }
                
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

