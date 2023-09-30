#include <bits/stdc++.h>
using namespace std;
const int m = 1000000007;
const int maxn = 1007;
typedef long long int lli;
lli DP[maxn];
int pass[maxn];
int main (){
    int n;
    cin>>n;
    vector<int> p(n+1);
    for(int i = 1;i<=n;i++)cin>>p[i];
    DP[1] = 2;
    for(int i = 2;i<=n;i++){
        int x =i;
        DP[i]= 1;
        for(int j = 1;j<=i;j++)pass[j] = 0;
        while(p[x]!= 1 && x!= p[x]){
            x = p[x];
            pass[x] = 1;
            DP[i]++;
        }
        x = p[x];
        DP[i]++;
        for(int j = x;j<i;j++){
            if(pass[j])
                DP[i]++;
            else 
                DP[i]+= DP[j];
            
            DP[i]%=m;                
        }
    }
    lli ans = 0;
    for(int i = 1;i<=n;i++){
        ans+=DP[i];
        ans%=m;
    }
    cout<<ans<<endl;
    return 0;
}