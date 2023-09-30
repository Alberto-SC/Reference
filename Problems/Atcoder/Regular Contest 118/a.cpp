#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const long double eps = 1e-9;
signed main(){__
	int t= 1,n;
    cin>>t>>n;
    int a = (100+t)/__gcd(100+t,t);
    int b = 100/__gcd(100+t,t);
    long double x = (a*1.0)/(b*1.0);
    long double diff= (1.0*x)-1;
    cout<<fixed<<setprecision(10);
    for(int i = 2798;i<=2802;i++){
        cout<<i<<" "<<i*x<<endl;
    }
    int z = n/diff;
    int ld = n/diff;
    cout<<fmod(n,diff)<<endl;
    cout<<z*diff<<endl;
    cout<<ld<<endl;
    int s = 2799.0*x;
    int s1 = 2800.0*x;
    int s2 = 2801.0*x;
    cout<<s<<" "<<s1<<" "<<s2<<endl;
    if(fmod(n,diff)>=eps)z++;
    int y = z+(n-1);
    cout<<y<<endl;
    return 0;
}  

// 20 574