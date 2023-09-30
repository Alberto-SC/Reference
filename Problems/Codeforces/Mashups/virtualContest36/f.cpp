#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> bit(maxn);

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-= idx&-idx)res+=bit[idx];
    return res;
}

void add(int idx,int val){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=val;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}

signed main(){__
	int t= 1,n;
    cin>>n>>t;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> pref(1,0);
    for(int i = 0;i<n;i++)
        pref.push_back(pref.back()+nums[i]);
    
    sort(pref.begin(),pref.end());
    pref.resize(unique(pref.begin(),pref.end())-pref.begin());
    int posz = lower_bound(pref.begin(),pref.end(),0)-pref.begin();
    add(posz,1);
    int ans = 0;
    int s = 0;
    for(int i = 0;i<n;i++){
        s+=nums[i];
        int idx = lower_bound(pref.begin(),pref.end(),(s-t)+1)-pref.begin();
        ans+=sum(idx,n+1);
        idx = lower_bound(pref.begin(),pref.end(),s)-pref.begin();
        add(idx,1);
    }
    cout<<ans<<endl;
    return 0;
}  
