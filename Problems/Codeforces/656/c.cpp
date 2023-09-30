#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int suff = 0;
        for(int i = n-1;i>=0;i--){   
            if(nums[i]<nums[i+1]){suff = i;break;}       
        }
        int last = 0;
        for(int i = suff;i>=1;i--){
            if(nums[i]<nums[i-1]){last = i;break;}
        }
        cout<<last<<endl;
    }
    return 0;
}