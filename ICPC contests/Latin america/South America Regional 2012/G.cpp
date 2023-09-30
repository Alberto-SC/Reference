#include <bits/stdc++.h>
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

int mov[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
ll r , c;

int BFS(ll x , ll y , vector<string> &matrix)
{
    queue<pll> cola;
    cola.push(pll(x,y));
    ll ans = 1;
    matrix[y][x] = 'x';
    pll aux;
    while(!cola.empty())
    {
        aux = cola.front();
        cola.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
           x = aux.xx+mov[i][0];
           y = aux.yy+mov[i][1];
           if(x < 0 || y < 0 || x >= c || y >= r)
                continue;
            if(matrix[y][x] == '.')
            {
                ans++;
                matrix[y][x] = 'x';
                cola.push(pll(x,y));
            }
        } 
    }
    cout << ans << " ANS\n";
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> r >> c)
    {
        vector<string> matrix(r);
        for(int i = 0 ; i < r ; i++)
            cin >> matrix[i];
        ll n;
        bool ans = false;
        for(int i = 0 ; i < r && !ans ; i++)
        {
            for(int j = 0 ; j < c && !ans ; j++)
            {
                if(matrix[i][j] == '.')
                n = BFS(j,i,matrix);
                if(n%2 != 0)
                {
                    ans = true;
                }
            }
        }
        if(ans)
            cout << "1\n";
        else
            cout << "2\n";    
    }
  

    return 0;
}

