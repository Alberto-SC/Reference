#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,id = 1;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        cout<<"Case #"<<id++<<": "<<h<<" "<<m<<" "<<s<<" "<<n<<endl;
    }
    return 0;
}  
