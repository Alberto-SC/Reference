#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define ld long double
signed main(){__
	int t= 1,n,D,h;
    while(t--){
        cin>>n>>D>>h;
        vector<pair<ld,ld>> nums(n);
        for(auto &[x,y]:nums)cin>>x>>y;
        ld l = 0,r = D;
        int cont = 1000;
        while(cont--){
            ld mid = (l+r)/2.0;
            ld m = (h-mid)/(D-0.0);
            bool flag = true;
            for(int i = 0;i<n;i++){
                ld y = (nums[i].first*m)+mid;
                if(isgreater(nums[i].second,y))flag = false;
            }
            if(flag)r = mid;
            else l = mid;
        }
        cout<<fixed<<setprecision(10);
        cout<<r<<endl;
    }
    return 0;
}  
