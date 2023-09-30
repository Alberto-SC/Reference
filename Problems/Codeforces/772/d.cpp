#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
const int mod = 1e9+7;

signed main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){ 
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c;
        vector<bool> n2(n,true),n4(n,true);
        for(int i = 0;i<n;i++)
            mp[nums[i]] = i;
        for(int i = 0;i<n;i++){
            int x = nums[i];
            while(x<=1e9){
                x*=2;
                x++;
                if(mp.count(x)){
                    n2[mp.count(x)] = false;
                }
            }
            x = nums[i];
            while(x<=1e9){
                x*=4;
                if(mp.count(x)){
                    n4[mp.count(x)] = false;
                }
            }
        }
        int ans = 0;

        for(int i = 0;i<n;i++){
            if(n2[i]){

            }
            if(n4[i]){
                
            }
        }
        cout<<ans<<endl; 
    }
    return 0;
}