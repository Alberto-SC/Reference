#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__	
    int n;
    cin>>n;
    vector<int> nums(n);
    int x = 0;
    for(auto &c:nums)cin>>c,x^=c;
    vector<int> bs(60);
    int y = 0;
    for(int b = 55;b>=0;b--){
        for(int i = 0;i<n;i++){
            if((nums[i]>>b)&1)bs[b]++;
        }
        if(bs[b]%2 ==0 && bs[b]>0){
            y|=(1ll<<b);
        }
    }
    cout<<x+(2*y)<<endl;
    return 0;
} 
