#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli maxn = 200007;

lli DP[2][maxn];
vector<lli> nums(maxn);
lli n;
vector<bool> vis(maxn,false);
int main(){
    cin>>n;
    for(lli i = 1;i<n;i++)cin>>nums[i];
    for(lli i = 1;i<n;i++){
        vector<bool> vis(n,false);
        vis[0] = true;
        int idx = i;
        int y = i;
        bool flag = false;
        while(1){
            if(vis[idx]){y = -1;break;}
            vis[idx] = true;
            y+=nums[idx];
            if(!flag)
                idx-=nums[idx];
            else 
                idx+=nums[idx];
            if(idx>=n)break;
            if(idx<0)break;
            flag = !flag;
        }
        cout<<y<<endl;
    }
    return 0;
}