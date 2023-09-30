#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    double t = 1,n1,n2,n12;
    cin>>n1>>n2>>n12;
    double x = ((n1+1)*(n2+1))/(n12+1);
    x--;
    cout<<fixed<<setprecision(0);
    cout<<floor(x)<<endl; 
    
    return 0;
}

