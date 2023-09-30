#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,N;
    while(T--){
        cin>>N;
        vector<int> nums(N);
        for(auto &c:nums)cin>>c;        
        vector<bool> vol(N+2,false);
        int sold = 0;
        for(int i=0;i<N;i++){
            if(nums[i]>=vol.size())sold++;
            else if(vol[nums[i]])sold++;
            else vol[nums[i]] = true;
        }
        int L = 1;
        int R = N+1;
        while(true){
            while(vol[L])L++;
            while(R!=0&&!vol[R])R--;
            if(sold>=2){
                sold-=2;
                vol[L] = true;
            }
            else{
                if(L>=R)break;
                vol[R] = false;
                sold++;
            }
        }
        cout<<L-1<<endl;
    }
    return 0;
}
