#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int sz = 100;

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n-1);
    iota(nums.begin(),nums.end(),1);
    vector<int> masks;
    int mx = 1;
    for(int mask = 1;mask< 1<<(n-1);mask++){
        int x =1;
        for(int j = 0;j<n-1;j++){
            if((mask>>j)&1)
                (x*=nums[j])%=n;
        }
        if(x==1){
            bitset<sz> bs(mask);
            if(bs.count()==mx){
                masks.push_back(mask);
            }
            else if(bs.count()>mx){
                mx = bs.count();
                masks.clear();
                masks.push_back(mask);
            }
        }
    }
    for(int i = 0;i<masks.size();i++){
        bitset<sz> b(masks[i]);
        for(int j = 0;j<n-1;j++){
            if(b[j])cout<<j+1<<" ";
        }
        cout<<endl;
        // cout<<b<<endl;
    }
    return 0;
}  
