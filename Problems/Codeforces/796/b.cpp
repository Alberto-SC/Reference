#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int od = 0,p = 0;
        for(auto &c:nums){
            cin>>c;
            if(c&1)od++;
            else p++;
        }
        if(od){
            cout<<p<<endl;
        }
        else{
            int mn = 1e9;
            for(int i = 0;i<n;i++){
                int x = nums[i];
                int cont = 0;
                while(x%2==0){
                    x/=2;
                    cont++;
                }
                mn = min(mn,cont);
            }
            cout<<mn+(p-1)<<endl;
        }
    }
    return 0;
}