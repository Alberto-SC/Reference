#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli DP[5007][5007];
const lli mod = 1e9+7;


int main(){
    int n,a,b,k;
    cin>>n>>a>>b>>k;
    for(int i = 1;i<=n;i++){
        if(abs(a-i)<abs(b-a) && i!=a)DP[i][0] = DP[i-1][0]+1;
        else DP[i][0] = DP[i-1][0];
    }
    // for(int i = 0;i<=n;i++)cout<<DP[i][0]<<" ";
    // cout<<endl;
    for(int i = 1;i<k;i++){
        for(int j = 1;j<=n;j++){
            if(j==b){DP[j][i] = DP[j-1][i];continue;}
            if(j<b){
                int r = ((b-j)/2);
                r-=((b-j)%2==0);
                // cout<<"R ";
                // cout<<j+r<<" "<<DP[j+r][i-1]<<endl;
                DP[j][i] = DP[j-1][i]+DP[j+r][i-1];
                // cout<<DP[j][i]<<endl;
                if(j+r>=j){
                    int x = DP[j][i-1]-DP[j-1][i-1];
                    DP[j][i]-=x;
                    if(DP[j][i]<0)DP[j][i]+=mod;
                }
                DP[j][i]%=mod;
            }
            else{
                int l = ((j-b)/2);
                l++;
                // cout<<"L "; 
                // cout<<b+l<<" "<<DP[b+l][i-1]<<endl;
                DP[j][i] = DP[j-1][i]+(DP[n][i-1]-DP[(b+l)-1][i-1]);
                // cout<<DP[j][i]<<endl;
                if(b+l<=j){
                    int x = DP[j][i-1]-DP[j-1][i-1];
                    DP[j][i]-=x;
                    if(DP[j][i]<0)DP[j][i]+=mod;
                }
                DP[j][i]%=mod;
            }
        }
        // for(int j = 0;j<=n;j++)
        //     cout<<DP[j][i]<<" ";
        // cout<<endl;
    }
    cout<<DP[n][k-1]<<endl;
    return 0;
}