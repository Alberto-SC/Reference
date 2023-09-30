#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 10000;
vector<int> sums;
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

vector<vector<int>> DP;

int n,m;
const int inf = 1e16;
int solve(int idx,int k){
    if(k ==0)return 0;
    if(idx>=sums.size())return -inf;
    int &x = DP[idx][k];
    if(x != -1)
        return x;
    x = max(solve(idx+m,k-1)+sums[idx],solve(idx+1,k));
    return x;
}

signed main(){__
	int t= 1,k;
    while(t--){
        cin>>n>>m>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sums.resize((n-m)+1);
        DP.resize(n,vector<int>(k+1,-1));
        for(int i = 0;i<n;i++)
            add(i,nums[i]);

        for(int i = 0;i<(n-m)+1;i++){
            sums[i] = sum(i,(i+m)-1);
        }
        cout<<solve(0,k)<<endl;
    }
    return 0;
}  
