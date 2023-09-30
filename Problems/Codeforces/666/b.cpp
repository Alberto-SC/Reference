#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli maxn = 1000000000;
const lli inf = 1000000000000000;
int main(){__
    lli n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    lli best =inf;
    lli pw;
    for(lli p = 1;p<=100000;p++){
        lli ans = 0;
        lli aux = 1;
        bool flag = true;
        for(int i = 0;i<n;i++){
            ans+=abs(nums[i]-aux);
            // cout<<"("<<aux<<" , "<<nums[i]<<")  ";
            aux*=p;
            if(aux>((n+1)*maxn) && i<n-1){flag = false;break;}
        }
        // cout<<endl;
        if(flag){   
            if(ans <best)
                best = ans,pw = p;
        }
        // cout<<p<<" "<<ans<<endl;
    }
    cout<<best<<endl;
    return 0;
}

