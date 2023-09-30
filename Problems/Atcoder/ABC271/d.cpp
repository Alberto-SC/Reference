#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<pair<int,int>> nums;

int dp[107][10007];
int pos[107][10007];
int S,n;
bool solve(int idx,int sum = 0){
    if(idx ==n ){
        return sum == S;
    }
    if(sum>S)return false;
    int &x = dp[idx][sum];
    if(x!=-1)return x;

    bool ans = false;
    bool ans1 = solve(idx+1,sum+nums[idx].first);
    bool ans2 = solve(idx+1,sum+nums[idx].second);
    if(ans1)
        ans = true,pos[idx][sum] = 0;
    if(ans2)
        ans = true,pos[idx][sum] = 1;
    return x = ans;
}

signed main(){__
    int T = 1;
    while(T--){
        cin>>n>>S;
        nums.resize(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i].first;
            cin>>nums[i].second;
        }
        memset(dp,-1,sizeof(dp));
        if(solve(0,0)){
            int sum = 0;
            cout<<"Yes"<<endl;
            for(int i = 0;i<n;i++){
                if(pos[i][sum] == 0)cout<<"H",sum+=nums[i].first;
                else cout<<"T",sum+=nums[i].second;
            }
            cout<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}