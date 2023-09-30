#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
typedef long double ld;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(vector<lli> nums,lli add,int k){
    lli sum = 0;
    nums[0]+=add;
    sum = nums[0];
    int n = nums.size();
    for(int i = 1;i<n;i++){
        ld p = (nums[i]*1.0)/sum;
        if(isgreater(p,k/100.0))return false;
        sum+=nums[i];
    }
    return true;
}
int main(){__
	int t= 1,n,k;
    cin>>t;
    cout<<fixed<<setprecision(10);
    while(t--){
        cin>>n>>k;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        lli l = -1,r = 1e12+1;
        while(l+1<r){
            lli m = (l+r)>>1;
            if(check(nums,m,k))
                r = m;
            else
                l = m;
        }
        cout<<r<<endl;
    }
    return 0;
}  

