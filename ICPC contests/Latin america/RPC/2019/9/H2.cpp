#include <bits/stdc++.h>
#define INF 1LL<<40
#define xx first
#define yy second
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

struct Grafo
{
    vvll Fx;
    vll v;
    Grafo(ll n)
    {
        v.assign(n,0);
        Fx.assign(n,vll());
    }
    void join(ll x , ll y)
    {
        Fx[x].push_back(y);
        Fx[y].push_back(x);
    }
    ll fillNode(ll x , ll p , ll c1 , ll c2)
    {
        bool edge = true;
        ll ans = Fx[x].size();
        vll::iterator it;
        for(it = Fx[x].begin() ; it != Fx[x].end() ; it++)
        {
            if(*it == p || *it == c1 || *it == c2)
                continue;
            ans += fillNode(*it,x , c1 , c2);
            edge = false;
        }
        v[x] = ans;
        if(edge)
            ans = 1;
        return ans;
    }
    ll hunt(ll r , ll c1  , ll c2)
    {
        ll ans = 0;
        ll mov = 0;
        pll mx(-1,0);
        vll::iterator it;
        while(r != c1 && r != c2)
        {
            bool ad1 = false , ad2 = false;
            for(it = Fx[c1].begin() ; it != Fx[c1].end() && !ad1 ; it++)
                ad1 |= (*it == r);
            for(it = Fx[c2].begin() ; it != Fx[c2].end() && !ad2 ; it++)
                ad2 |= (*it == r);
            if(ad1 && ad2)
            {
                if(Fx[r].size() < 4)
                    return ans+1;
            }
            else if(ad1)
                mov = 1;
            else if(ad2)
                mov = 0;
            mx = pll(-1,0);
            fillNode(r,-1,c1,c2);
            for(it = Fx[r].begin() ; it != Fx[r].end() ; it++)
            {
                 if(*it == c1 || *it == c2)
                    continue;
                if(v[*it] > mx.yy)
                {
                    mx.xx = *it;
                    mx.yy = v[*it];
                }
            }
            if(mx.xx == -1)
                return ans+1;
            if(mov)
                c2 = mx.xx;
            else
                c1 = mx.xx;
            ans++;
            mx = pll(-1,0);
            fillNode(r,-1,c1,c2);   
            for(it = Fx[r].begin() ; it != Fx[r].end() ; it++)
            {
                 if(*it == c1 || *it == c2)
                    continue;
                if(v[*it] > mx.yy)
                {
                    mx.xx = *it;
                    mx.yy = v[*it];
                }
            }
             if(mx.xx == -1)
                return ans+1;
            else
                r = mx.xx;
        }
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n , a , b , c , x , y;
    cin >> n >> a >> b >> c;
    Grafo g(n);
    for(int i = 0 ; i < n-1 ; i++)
    {
        cin >> x >> y;
        g.join(x-1,y-1);
    }

    cout << g.hunt(a-1,b-1,c-1) << '\n';
  
    return 0;
}