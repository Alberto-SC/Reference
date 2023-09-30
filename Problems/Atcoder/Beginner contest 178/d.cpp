#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;

int main(){__
    lli t = 1,n;
    while(t--){
        lli s;
        cin>>s;
        vector<lli> DP(s+1,0);
        DP[0] =1;

        for(int i = 3;i<=s;i++){
            for(int j = 3;j<=s;j++){
                if(i-j>=0)
                    (DP[i]+=DP[i-j])%=mod;
            }
        }
        cout<<DP[s]<<endl;
    }
    return 0;
}

