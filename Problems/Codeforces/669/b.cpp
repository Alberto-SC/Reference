#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = -1,idx;
        for(int i = 0;i<n;i++){
            if(nums[i]>mx){
                idx = i;
                mx = nums[i];
            }
        }
        vector<bool> used(n);
        used[idx] = true;
        cout<<mx<<" ";
        int gcd = mx;
        for(int i = 1;i<n;i++){
            mx  = -1;
            for(int j = 0;j<n;j++){
                if(!used[j]){
                    if(__gcd(gcd,nums[j])>mx){
                        mx = __gcd(gcd,nums[j]);                                     
                        idx = j;
                    }
                }
            }
            gcd = mx;
            cout<<nums[idx]<<" ";
            used[idx] =true;
        }
        cout<<endl;
    }  
    return 0;
}




