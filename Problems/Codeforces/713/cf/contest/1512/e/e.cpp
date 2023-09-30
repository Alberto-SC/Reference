#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[501][125251];
const int sz = 5;
vector<int> A(501);
bitset<sz> ans;
int k,n;  
int solve(int i, int x,bitset<sz> mask){
    if(x<0){return 0;}
    cout<<x<<" "<<mask<<" "<<i<<" "<<dp[i][x]<<endl;
    if(i==n){
        if(x==0){
            if((int)mask.count()==k){
                ans = mask;
                return 1;
            }
            else return 0;
        }
        else
            return 0;
    }
    if(dp[i][x]!=-1)
        return dp[i][x];
    dp[i][x]= solve(i+1,x,mask);
    bitset<sz> nmask = mask;
    nmask[i] = 1;
    dp[i][x]+=solve(i+1,x-A[i],nmask);
    return dp[i][x];
}

signed main(){__
	int t= 1,l,r,s;
    iota(A.begin(),A.end(),1);
    cin>>t;
    int id = 1;
    while(t--){
        cin>>n>>l>>r>>s;
        k = (r-l)+1;
        vector<int> res(n,-1);
        vector<int> used(n);
        bitset<sz> zero;
        for(int i = 0;i<=n+1;i++){
            for(int j = 0;j<=s+1;j++)
                dp[i][j] =-1;
        }
        if(solve(0,s,zero)){
            int idx = l-1;
            for(int i =0;i<n;i++){
                if(ans[i]){
                    used[i]  = true;
                    res[idx++] = i+1;
                }
            }
            idx = 0;
            for(int i = 0;i<n;i++){
                if(used[i])continue;
                while(idx<n && res[idx]!=-1){
                    idx++;
                }
                res[idx] = i+1;
            }
            for(auto c:res)cout<<c<<" ";
            cout<<endl;
        }   
        else {
            cout<<-1<<endl;
        }
        id++;
    }
    return 0;
}  
