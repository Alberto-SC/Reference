#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int sum = 0,mx = 0;
    for(int i = 0;i<n;i++){
        sum+=nums[i];
        mx = max(mx,sum);
    }
    cout<<mx+100<<endl;
    return 0;
}  

