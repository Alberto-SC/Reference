#include <bits/stdc++.h>
#define INF 1LL<<40
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll DP(300005 , -1);

ll n , m;

ll dp(ll x , vll &v)
{
    if(x >= n)
        return 0;
    if(DP[x] != -1)
        return DP[x];
    DP[x] = max(dp(x+m,v)+v[x], dp(x+1,v));
    return DP[x];
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vll v(n);
    for(int i = 0 ; i < n ; i++)
        cin >> v[i];
    cout << dp(m,v) << '\n';
    return 0;
}