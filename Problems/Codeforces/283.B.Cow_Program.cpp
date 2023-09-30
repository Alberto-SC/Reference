#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli maxn = 200007;

lli DP[2][maxn];
lli V[2][maxn];
vector<lli> nums(maxn);
lli n;

lli dp(int idx, bool dir){
    if (idx<0||idx>=n)
        return 0;
    if (V[dir][idx] == 1)
        return DP[dir][idx];
    lli &ans = DP[dir][idx];
    if (V[dir][idx] == -1){
        V[dir][idx] = 1;
        return ans = -1;
    }
    V[dir][idx] = -1;
    if(dir)
        ans = dp(idx-nums[idx],!dir);
    else
        ans = dp(idx+nums[idx],!dir);
    V[dir][idx] = 1;
    if (ans != -1)
        ans += nums[idx];
    return ans;
}

int main(){
    cin>>n;
    for(lli i = 1;i<n;i++)cin>>nums[i];
    for(lli i = 1;i<n;i++){
        lli ans = dp(i,1);
        if(ans !=-1)cout<<ans+i<<endl;
        else cout<<-1<<endl;
    }
    
    return 0;
}