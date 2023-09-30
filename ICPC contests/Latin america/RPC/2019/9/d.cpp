#include <bits/stdc++.h>
#define INF 1LL<<40
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct Grafo
{
    vvll Fx;
    void insert()
    {
        Fx.push_back(vll());
    }
    void join(ll x , ll y)
    {
        Fx[x].push_back(y);
    }
    bool find(ll x , ll p , ll y)
    {
        bool ans = false;
        if(x == y)
            return true;
        vll::iterator it;
        for(it = Fx[x].begin() ; it != Fx[x].end() ; it++)
        {
            if(*it == p)
                continue;
            ans |= find(*it , x , y);
        }
        return ans;
    }    
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   ll n , m , vecs = 0, x , y;
   cin >> n >> m;
    string a , aux , b;
    map<string,ll> mp;
    Grafo g1 = Grafo();
    Grafo g2 = Grafo();
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> aux >> aux >> aux >> b;
        if(!mp.count(a))
        {
            mp[a] = vecs++;
            g1.insert();
            g2.insert();
        }
        if(!mp.count(b))
        {
            mp[b] = vecs++;
            g1.insert();
            g2.insert();
        }
        x = mp[a];
        y = mp[b];
        g1.join(x,y);
        g2.join(x,y);
    }
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> aux >> aux >> aux >> b;
        x = -1;
        y = -1;
        if(mp.count(a))
            x = mp[a];
        if(mp.count(b))
            y = mp[b];
        if(x == -1 || y == -1)
             cout << "Pants on Fire\n";
        else if(g1.find(x, -1 , y))
            cout << "Fact\n";
        else if(g2.find(y, -1 , x))
            cout << "Alternative Fact\n";
        else
            cout << "Pants on Fire\n";
        
        
    }
    return 0;
}