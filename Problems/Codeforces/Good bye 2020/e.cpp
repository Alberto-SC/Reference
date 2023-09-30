#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;
 

int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        vector<lli> f(60);
        for(int i = 0;i<60;i++){
            for(int j = 0;j<n;j++){
                f[i] += ((nums[j]>>i)&1);
            }
        }
        lli ans = 0;
        for(int i = 0;i<n;i++){
            lli sum1 = 0,sum2 = 0;
            for(int j = 0;j<60;j++){
                sum1+= ((1ll<<j)%mod)*((nums[i]>>j)&1)*f[j];
                sum1%=mod;
                if((nums[i]>>j)&1)
                    (sum2+= ((1ll<<j)%mod)*n)%=mod;
                else
                    (sum2+= ((1ll<<j)%mod)*(f[j]))%=mod;

            }   
            (ans+=(sum1*sum2))%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}  

