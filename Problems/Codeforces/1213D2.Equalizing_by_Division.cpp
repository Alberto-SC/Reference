#include <bits/stdc++.h>
using namespace std;
int costs[200007][25];
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    for(int i = 0;i<n;i++){
        int aux = nums[i];
        int cont = 0;
        while(aux){
            costs[aux][cont]++;
            cont++;
            aux>>=1;
        }
        costs[0][cont]++;
    }
    int ans = 0,mn = 1000000007;
    for(int i = 0;i<=200000;i++){
        int x = k;
        ans = 0;
        int j;
        for(j = 0;j<25;j++){
            // cout<<costs[i][j]<<" ";
            if(x-costs[i][j]<0)break;
            else ans+=costs[i][j]*j,x-=costs[i][j];
        }
        // cout<<endl;
        // cout<<x<<" "<<ans<<" "<<j<<endl;
        if(j == 25 && x)continue;
        ans += x*j;
        mn = min(ans,mn);
    }
    cout<<mn<<endl;
    return 0;
}