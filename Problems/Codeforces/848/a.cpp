#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        bool f1 = false;
        bool f2 = false;
        for(int i = 0;i<n-1;i++){
            if(nums[i]== -1 && nums[i+1]==-1)
                f1 = true;
            if(nums[i]!=nums[i+1])f2 = true;
        }
        if(f1)s+=4;
        else if(f2)s+=0;
        else s-=4;
        cout<<s<<endl;
    }
    return 0;
}