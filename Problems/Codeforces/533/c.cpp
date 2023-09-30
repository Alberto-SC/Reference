#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
lli mod = 1e9+7;
lli DP[200007][3];

lli a,b,c,n;
lli solve(int idx,int sum){
    if(idx == n)
        return sum== 0;
    
    lli &x = DP[idx][sum];
    if(x!= -1)return x;
    lli ans = 0;
    if(c)(ans+=((solve(idx+1,sum)*c)%mod))%=mod;
    if(a)(ans+=((solve(idx+1,(sum+1)%3)*a)%mod))%=mod;
    if(b)(ans+=((solve(idx+1,(sum+2)%3)*b)%mod))%=mod;
    return x = ans;
}

int main(){__
    int t = 1,l,r;
    cin>>n>>l>>r;
    a = b= c= ((r-l)+1)/3;
    int x = ((r-l)+1)%3;
    if(((r-l)+1)%3){
        if(l%3 == 0){
            c++;
            if(x==2)
                a++;
        }
        else if(l%3 ==1){
            a++;
            if(x==2)
                b++;
        }
        else{
            b++;
            if(x ==2)
                c++;
        }            
    }
    for(int i =0;i<n+1;i++){
        DP[i][0] = DP[i][1] = DP[i][2] = -1;
    }
    // memset(DP,-1,sizeof(DP));
    // cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<solve(0,0)<<endl;
    return 0;
}

