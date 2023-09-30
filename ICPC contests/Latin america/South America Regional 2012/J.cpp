#include <bits/stdc++.h>
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;

struct Grafo
{
    vvll Fx;
    vll v;
    vll n;
    Grafo(ll x)
    {
        Fx.assign(x,vll());
        v.assign(x,0);
        n.assign(x,0);
    }
    void unir(ll x , ll y)
    {
        Fx[x].push_back(y);
    }
    ll meet(ll x , ll y)
    {
        v.assign(Fx.size() , 0);
        n.assign(Fx.size() , 0);
        if(x == y)
            return 0;
        queue<ll> cola;
        cola.push(x);
        cola.push(y);
        v[x] = 1;
        v[y] = 2;
        vll::iterator it;
        ll aux;
        while(!cola.empty())
        {
            aux = cola.front();
            cola.pop();
            for(it = Fx[aux].begin() ; it != Fx[aux].end() ; it++)
            {
                if(v[*it] == 0)
                {
                    cola.push(*it);
                    v[*it] = v[aux];
                    n[*it] = n[aux]+1;
                }else if(v[*it] != v[aux])
                {
                    return n[aux]+n[*it]+1;
                }
            }
        }
        return -1;

    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n , k , a , b;
    while(cin >> n)
    {
        Grafo g(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a;
            g.unir(i,a-1);
        }
        cin >> k;
        while(k--)
        {
            cin >> a >> b;
            cout << g.meet(a-1,b-1) << '\n';
        }
    }

    return 0;
}

