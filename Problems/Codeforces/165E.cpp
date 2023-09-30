#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    int N = 22;
    vector<int> F(1<<N,-1);
    for(int i = 0;i<n;i++){
        F[nums[i]] = nums[i];
    }

    for(int i = 0;i < N; ++i) 
        for(int mask = 0; mask < (1<<N); ++mask){
            if(mask & (1<<i))
                F[mask] = max(F[mask],F[mask^(1<<i)]);
    }


    for(int i = 0;i<n;i++){
        int x = 0;
        for(int j = 0;j<N;j++){
            if(!(nums[i] & (1<<j)))
                x|=1<<j;
        }
        bitset<5> bs(nums[i]);
        bitset<5> bs2(x);
        // cout<<bs<<endl<<bs2<<endl;
        
        // cout<<endl;
        cout<<F[x]<<" ";
    }
    cout<<endl;
    return 0;
}