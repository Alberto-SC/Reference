#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
typedef long double ld;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

ld resistencia(ld x,vector<ld> nums){
    ld total = 0;
    for(int i = 0;i<nums.size();i++){
        total+= 1/((1/x)+(1/nums[i]));
    }
    return total;
}
int main(){__
	int t= 1,n,R;
    while(t--){
        cin>>n>>R;
        vector<ld> nums(n);
        for(auto &c:nums)cin>>c;
        ld l= 0,r = 1000000;
        int cont = 100;
        while(cont--){
            ld m = (l+r)/2;
            if(resistencia(m,nums)<R)
                l = m;
            else 
                r = m;
            
        }
        cout<<fixed<<setprecision(10);
        cout<<r<<endl;
    }
    return 0;
}  

