#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int maxn = 2000;
vector<int> bit(maxn);

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}
void add(int idx,int val){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=val;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}
void print(){
    for(int i = 0;i<=8;i++)
        cout<<sum(i,i)<<" ";
    cout<<endl;
}

signed main(){__
    int n,q,l,r;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    cin>>q;
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans+=sum(nums[i],n);
        add(nums[i],1);    
    }
    for(int i = 0;i<n;i++)
        add(nums[i],-1);    
    
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        int inv = 0;
        int N = ((r-l)+1)>>1;
        if(N&1)ans++;
        cout<<(ans&1?"odd":"even")<<endl;
    
    }
    cout<<endl;
    return 0;
}  
