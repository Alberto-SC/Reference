#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1;
    long long n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int max_bit = 0;
        for(auto &c:nums){
            cin>>c;
            for(int i = 31;i>=0;i--){
                if((c>>i)&1)max_bit = max(i,max_bit);
            }
        }
        int N = (1<<(max_bit+1));
        vector<int> mp(2*N);
        mp[0] = 1;
        long long ans = (n*(n+1))/2;
        int x = 0;
        long long bad = 0;
        for(int i = 0;i<n;i++){
            x^=nums[i];
            for(int p = 0;p*p<=N;p++){
                int need = x^(p*p);
                bad+=mp[need];
            }
            mp[x]++;
        }
        cout<<ans-bad<<endl;
    }
    return 0;
}