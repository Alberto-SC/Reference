#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
typedef long double ld;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
double DP[1000007];
int main(){__
	int t,n,a,b;
    cin>>n>>a>>b;
    double s = (b-a)+1;
    double x = a!=0?1:s/(s-1);
    int l = 0,r = 1;
    double sum = 0;
    for(int i = 1;i<=n;i++){
        DP[i] = x*(1+((1.0/s)*sum));
        // cout<<i<<" "<<DP[i]<<" "<<sum<<" "<<1.0/s<<" "<<sum*(1.0/s)<<" "<<l<<" "<<r<<endl;
        if(i>=a)sum+=DP[r++];
        if(r-1-l+1>(a?(int)s:(int)s-1))sum-=DP[l++];
    }
    cout<<fixed<<setprecision(10);
    cout<<DP[n]<<endl;
    return 0;
}  

