#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

const int MOD = 998244353;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=MOD;
        (a*=a)%=MOD;
        b>>=1;
    }
    return x;
}

signed main(){__
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> prefMax(n);
        vector<int> suffMin(n);

        for(int i=0;i<n;i++){
            if(i == 0)prefMax[i] = nums[i];
            else prefMax[i] = max(prefMax[i-1],nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(i == n-1)suffMin[i] = nums[i];
            else suffMin[i] = min(suffMin[i+1],nums[i]);
        }

        int free = 0;
        for(int i = 0;i<n;i++){
            bool flag = true;
            if(i && prefMax[i-1] > nums[i])flag = false;
            if(i != n-1 && suffMin[i+1] < nums[i])flag = false;
            if(flag)free++;
        }
    
        int ans = mod_pow(2,free);
        if(free == n)ans--;
        if(ans<0)ans+=MOD;
        cout<<ans<<endl;

    }
    return 0;
}