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
    map<int,int> mp;
    vector<int> primes;
    for(int i = 2;i<=50;i++){
        bool flag = true;
        for(int j= 2;j<i;j++){
            if(i%j ==0)flag = false;
        }
        if(flag)primes.push_back(i);
    }
    int ans = 1;
    for(auto c:primes)ans*=c;
    for(int i = 1;i<(1<<15);i++){
        int y = 1;
        for(int j = 0;j<15;j++){
            if((i>>j)&1)
                y*=primes[j];
        }
        bool flag = true;
        for(int j = 0;j<n;j++){
            if(__gcd(nums[j],y)==1)flag = false;
        }
        if(flag)ans = min(ans,y);
    }
    return cout<<ans<<endl,0;
}  
