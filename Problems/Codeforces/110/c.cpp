#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;
int main(){
	int t,n;
    cin>>t;
    string s;
    lli DP[107][2507];
    for(int i = 0;i<=2500;i++)DP[0][i] = 0;
    DP[0][0] = 1;
    for(int i = 1;i<=100;i++){
        for(int j = 0;j<=2500;j++){
            lli x = 0;
            for(int k = 0;k<=25;k++){
                if(j-k>=0)
                    (x+=DP[i-1][j-k])%=mod;
            }
            DP[i][j] = x;
        }
    }
    cout<<endl;
    while(t--){
        cin>>s;
        n = s.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=s[i]-'a';
        }
        if(DP[n][sum]==0)cout<<0<<endl;
        else
            cout<<DP[n][sum]-1<<endl;
    }
    return 0;
}  


// klmbfxzb<

