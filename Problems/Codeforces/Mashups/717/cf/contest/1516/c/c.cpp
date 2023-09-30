#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int sz = 200007;
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0,im = 0,p = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s&1){
            cout<<0<<endl;
            continue;
        }
        bitset<sz> bs;
        bs[0]=1;
        for(auto c:nums)
            bs|=(bs<<c);
        if(bs[s/2]){
            int mn = 100,idx;
            for(int i = 0;i<n;i++){
                if(__builtin_ctz(nums[i])<mn){
                    mn = __builtin_ctz(nums[i]);
                    idx = i+1;
                }
            }
            cout<<1<<endl;
            cout<<idx<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}  
