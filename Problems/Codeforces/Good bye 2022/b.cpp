#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        iota(nums.begin(),nums.end(),1);
        int l = 0,r = n-1;
        int turn = 0;
        if(k==1){
            for(auto c:nums)cout<<c<<" ";
            cout<<endl;
            continue;
        }
        for(int i = 0;i<n;i++){
            if(i%(k-1) ==0)turn ^=1;
            if(turn)
                cout<<nums[r--]<<" ";
            else cout<<nums[l++]<<" ";
        }
        cout<<endl;
    }
    return 0;
}