#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007; 
vector<int> bit(maxn);

int sum(int idx){
    int x =0;
    for(++idx;idx>0;idx-= idx&-idx)x+=bit[idx];
    return x;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}

void add(int idx,int v){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=v;
}
signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        vector<int> U;
        int last = copy[0];
        U.push_back(last);
        for(int i = 0;i<n;i++){
            if(copy[i]!= last){
                last = copy[i];
                U.push_back(last);
            }
        }
        for(int i  = 0;i<n;i++){
            nums[i] = lower_bound(U.begin(),U.end(),nums[i])-U.begin();
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            int l = sum(0,nums[i]-1);
            int r = sum(nums[i]+1,n);
            ans+=min(l,r);
            add(nums[i],1);
        }
        cout<<ans<<endl;
        for(int i = 0;i<n;i++)
            add(nums[i],-1);
    }
    return 0;
}  
