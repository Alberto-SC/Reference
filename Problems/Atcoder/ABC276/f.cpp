#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> bit[2];
const int mod = 998244353;
int N = 200007;
void add(int idx,int v,int who){
    for(++idx;idx<N;idx+=idx &-idx)bit[who][idx]+=v;
}

int sum(int idx,int who){
    int res =0;
    for(++idx;idx>0;idx-=idx &-idx)res +=bit[who][idx];
    return res;
}

int sum(int l,int r,int who){
    return sum(r,who)-sum(l-1,who);
}

int mod_pow(int a,int b,int m){
    int x= 1;
    while(b){
        if(b&1)(x*=a)%=m;
        (a*=a)%=m;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T = 1,n;
    cin>>n;
    bit[0].resize(N);
    bit[1].resize(N);

    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    cout<<nums[0]<<endl;
    int last = nums[0];
    add(nums[0],1,0);
    add(nums[0],nums[0],1);
    for(int i = 1;i<n;i++){
        int count = sum(0,nums[i],0);
        int a1 = nums[i]*count*2;
        a1+=nums[i];
        int a2 = sum(nums[i]+1,N-1,1);
        a2*=2;
        a1%=mod;
        a2%=mod;
        int P = a1+a2+last;
        P%=mod;
        int ans = P*mod_pow(((i+1)*(i+1))%mod,mod-2,mod);
        ans%=mod;
        cout<<ans<<endl;
        last = P;
        add(nums[i],1,0);
        add(nums[i],nums[i],1);
    }   
    return 0;
}