#include <bits/stdc++.h>
 
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int main() {__
    int n,m;
    while(1){
        cin>>n>>m;
        if(n ==-1 && m ==-1)break;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        long long ans = 0;
        long long last = 0;
        for(int i = 0;i<n;i++){
            last += nums[i]*m;
            ans+=last;
        }
        cout<<ans<<endl;
    }
 
    return 0;
}