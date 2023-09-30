#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums){
            cin>>c;
            if(c%m==0)c/=m;
            else (c/=m)++;
        }
        int mx = *max_element(nums.begin(),nums.end());
        int idx = 0;
        for(int i = n-1;i>=0;i--){
            if(nums[i]==mx){
                idx = i+1;
                break;
            }
        }
        cout<<idx<<endl;
    }
    return 0;
}  
