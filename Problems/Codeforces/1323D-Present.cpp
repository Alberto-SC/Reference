#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int carry = 0;
    auto gauss = [&](int x){
        return (x*(x+1))/2;
    };
    int ans = 0; 
    for(int b = 0;b<4;b++){
        int o= 0,z = 0;
        for(int i = 0;i<n;i++){
            if((nums[i]>>b)&1)o++;
            else z++;
        }
        int y = z*o;
        if((y+carry)&1)ans+=(1<<b);
        y = gauss(o-1);
        if(y&1)carry=1;
        else carry = 0;
        cout<<ans<<" "<<carry<<endl;
    }
    cout<<ans<<endl;    
    return 0;
}  
