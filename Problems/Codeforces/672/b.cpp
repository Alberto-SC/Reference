#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;   
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        vector<lli> b(33,0);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<n;i++){
            b[__builtin_clz(nums[i])]++;
        }
        lli ans = 0;
        for(int i = 0;i<32;i++){
            if(b[i]>1)
            ans+= (b[i]*(b[i]-1))/2; 
        }
        cout<<ans<<endl;
    }
    return 0;
}

