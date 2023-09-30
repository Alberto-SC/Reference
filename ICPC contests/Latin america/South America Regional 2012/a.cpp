#include <bits/stdc++.h>
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

ll n , k;

ll dp(vpll &v , ll a , ll x , ll f , ll s)
{
    if(s == k)
        return f;
    ll ans = (ll)1<<60 , r;
    for(int i = x+1 ; i < n ; i++)
    {
        r = min(dp(v,a+v[i].yy,i,(v[i].xx-v[x].xx)*(v[x].yy+a)+f,s-1) , dp(v,a,i,f,s));
        ans = min(ans,r);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> k)
    {
        vpll v(n);
        for(int i = 0 ; i < n ; i++)
            cin >> v[i].xx >> v[i].yy;
        cout << dp(v,0,0,0,n) << '\n';
    }

    return 0;
}

