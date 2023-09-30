#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

vll ST(4*10005);

int update(ll v , ll l , ll r , ll x , ll y)
{
    if(y < l || y >= r)
    {
 //       cout << v << " " << ST[v] << '\n';
        return ST[v];
    }
    else if(r-l == 1)
    {
        if(x > 0)
            ST[v] = 1;
        else if(x == 0)
            ST[v] = 0;
        else
            ST[v] = -1;
   //     cout << v << " " << ST[v] << " " << x << '\n';
        return ST[v];
    }else
    {
        ll m = (l+r)/2;
        ST[v] = update(2*v,l,m,x,y)*update(2*v+1,m,r,x,y);
 //       cout << v << " " << ST[v] << '\n';
        return ST[v];
    }
}

int query(ll v , ll l , ll r , ll x , ll y)
{
    if(y < l || x >= r)
    {
    //    cout << "F\n";
        return 1;
    }
    else if(x <= l && r-1 <= y)
    {
    //    cout << "K\n";
        return ST[v];
    }
    else
    {
        ll m = (l+r)/2;
        ll ans = query(2*v,l,m,x,y)*query(2*v+1,m,r,x,y);
     //   cout << v << " " << ans << '\n';
        return ans; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    while(cin >> n >> k)
    {
        ll a , b ,ans;
        char c;
        ST.assign(4*n+5,0);
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a;
            update(1,1,n+1,a,i+1);
        }
        while(k--)
        {
            cin >> c >> a >> b;
            if(c == 'C')
                update(1,1,n+1,b,a);
            else
            {
                ans = query(1,1,n+1,min(a,b),max(a,b));
                if(ans == 1)
                    cout << '+';
                else if(ans == 0)
                    cout << '0';
                else
                    cout << '-';            
            }
        }
        cout << '\n';
    }
    return 0;
}

