#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
const int mod = 1e9 +7;
int DP[71][1<<19];
int masks[71];
int main(){
    int n;
    cin>>n; 
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> pos[2];
    pos[0].resize(71);
    pos[1].resize(71);
    for(int i = 1;i<=70;i++)pos[0][i] =1;
    for(int i = 0;i<n;i++){
        int x = pos[0][nums[i]];
        pos[0][nums[i]] = (pos[0][nums[i]]+ pos[1][nums[i]])%mod;
        pos[1][nums[i]] = (pos[1][nums[i]]+ x)%mod;
    }
    for(int i = 1;i<=70;i++){
        for(int j = 0;j<19;j++){
            int c = 0;
            int aux = i;
            while(aux%primes[j] == 0){
                c++;
                aux/=primes[j];
            }
            if(c&1)masks[i] |= (1<<j);
        }
    }
    DP[0][0] = 1;
    int max_mask = 1<<19;
    for(int i = 1;i<=70;i++){
        for(int mask = 0;mask<max_mask;mask++){
            DP[i][mask] = DP[i-1][mask]*1ll *pos[0][i]%mod;
            DP[i][mask] += DP[i-1][mask^masks[i]]*1ll*pos[1][i]%mod;
            DP[i][mask]%=mod;
        }
    }
    cout<<(DP[70][0]+mod-1)%mod<<endl;
    return 0;
}