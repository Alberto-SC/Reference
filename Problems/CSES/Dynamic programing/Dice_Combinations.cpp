#include <bits/stdc++.h>
using namespace std;
vector<int>DP(1000007,0);
const int mod = 1000000007;

int main(){
    int n;
    cin>>n;
    DP[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=6 && i-j>=0;j++){
            (DP[i]+=DP[i-j])%=mod;
        }
    }
    cout<<DP[n];
    return 0;
}