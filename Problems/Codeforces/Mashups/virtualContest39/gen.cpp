#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    n = 1500;
    vector<int> nums(n);
    iota(nums.begin(),nums.end(),1);
    random_shuffle(nums.begin(),nums.end());
    cout<<n<<endl;
    for(auto c:nums)cout<<c<<" ";
    cout<<endl;
    int q = 200000;
    cout<<q<<endl;
    for(int i =0;i<q;i++){
        cout<<1<<" "<<n<<endl;
    }
    return 0;
}  
