#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int n,m,k;

int main(){
    ios_base::sync_with_stdio(0);
    int t,c;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        vector<int>nums(n);
        for(auto &c:nums)cin>>c;
        int bf = m-1,bh = n-m;
        k = min(k,bf);
        int best = 0;
        for(int i = 0;i<=k;i++){
            int ans = (1e9)+5;
            for(int j = 0;j<=bf-k;j++){
                int ans2 = max(nums[i+j],nums[i+j+bh]);
                ans = min(ans,ans2);
            }
            best = max(best,ans);
        }   
        cout<<best<<endl;
    }
    return 0;
}