#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    vector<lli> fact(21);
    if(n ==2)return cout<<1<<endl,0;
    fact[0] =1;
    fact[1] = 1;
    for(int i = 2;i<=20;i++)
        fact[i]= fact[i-1]*i;
    cin>>n;
    lli x = fact[n];
    x/=(n*(n/2));
    cout<<x<<endl;
    return 0;
}

