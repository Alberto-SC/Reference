#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        lli sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        lli mx = *max_element(nums.begin(),nums.end());
        lli mn = *min_element(nums.begin(),nums.end());
        lli x = (n-1)*mx;
        lli y = x-sum;
        if(y<0){
            y = abs(y);
            lli z = (y/(n-1));
            if(y%(n-1))z++;
            x+= z*(n-1);
        }
        cout<<x-sum<<endl;

    }
    return 0;
}  

