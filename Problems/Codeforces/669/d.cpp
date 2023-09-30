#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
const int maxn = 300007;
const int inf = 1000000007;
vector<int> mxr(maxn,-1);
vector<int> lsr(maxn,-1);
int DP[maxn];
vector<int> nums(maxn);
int solve(int idx){
    int &x = DP[idx];
    if(x!= inf)return x;
    int j = mxr[idx];
    while(j!=-1){c  
        x = min(x,solve(j)+1);
        if(nums[mxr[j]]<nums[idx] || mxr[j]== -1)
            j = lsr[j];
        else j = -1;
    }
    j = lsr[idx];
    while(j!=-1){
        x = min(x,solve(j)+1);
        if(nums[lsr[j]]>nums[idx]|| lsr[j]== -1)
            j = mxr[j];
        else j = -1;
    }
    x = min(x,solve(idx+1)+1);
    return x;  
}

int main(){__
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    stack<pair<int,int>> s;
    for(int i = 0;i<n;i++)DP[i] = inf;
    s.push({nums[0],0});
    for(int i = 1;i<n;i++){
        while(!s.empty() && nums[i]>=s.top().x){
            mxr[s.top().y] = i;
            s.pop();
        }
        s.push({nums[i],i});
    }
    while(!s.empty())
        s.pop();
    s.push({nums[0],0});
    for(int i = 1;i<n;i++){
        while(!s.empty() && nums[i]<=s.top().x){
            lsr[s.top().y] = i;
            s.pop();
        }
        s.push({nums[i],i});
    }
    // for(int i = 0;i<n;i++)cout<<mxr[i]<<" ";
    // cout<<endl;
    // for(int i = 0;i<n;i++)cout<<lsr[i]<<" ";
    // cout<<endl;
    
    DP[n-1] = 0;
    solve(0);
    for(int i = 0;i<n;i++)cout<<DP[i]<<" ";
    cout<<endl;
    cout<<DP[0];
    return 0;
}

