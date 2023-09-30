#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x;
    map<string,int> mp = {{"Monday",0},{"Tuesday",1},{"Wednesday",2},{"Thursday",3},{"Friday",4},{"Saturday",5},{"Sunday",6}};
    string s;
    cin>>n>>s>>x;
    int idx = mp[s]-1,cont = 0;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        idx++;
        idx%=7;
        if(nums[i]>=x && idx<=4)cont++;
    }
    cout<<cont<<endl;
    return 0;
}  
