#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100;
vector<int> DP(maxn,-1);
vector<int> masks(maxn);
vector<string> nums(100007);
int n,m;
int solve(int idx,int sz = 0,int mask= 0){
    cout<<idx<<" "<<sz<<" "<<mask<<endl;
    if(idx == m)
        return __builtin_popcount(mask);
    
    int &x = DP[idx];
    if(x!=-1)return x;
    int ans = 0;
    ans = solve(idx+1,sz,mask);
    vector<int> all_(n);
    int cont = 0;
    for(int j = 0;j<61;j++){
        if((mask>>j)&1 || j == idx){
            for(int i = 0;i<n;i++){
                if(nums[i][j]=='1')
                    all_[i]++;
            }
            cont++;
        }
    }
    int szh =0;
    for(int i = 0;i<n;i++){
        if(all_[i]==cont)szh++;
    }
    if(szh>=(n+1)/2){
        int res = solve(idx+1,szh,mask|1<<idx);
        if(res>ans){
            ans = res;
            masks[idx] = masks[idx+1]|1<<idx;
        }
        }
    return x = ans;
}

signed main(){__
	int t= 1,p;
    cin>>n>>m>>p;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    bool flag = true;
    solve(0);
    for(int i = 0;i<m;i++)
        cout<<masks[i]<<" ";
    cout<<endl;
    bitset<63> ans(masks[0]);
    cout<<ans<<endl;
    return 0;
}  
