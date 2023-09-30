#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

ll pot(ll a , ll b)
{
    ll ans = 1;
    for(int i = 0 ; i < b ; i++)
        ans *= a;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vll v;
    ll a , b , c , d;
    ll K = 0 , H = 0;
    string x , y , z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    for(int i = 0 ; i < c ; i++)
    {
        if(z[i] == '*')
        {
           d = i;
        
            break;
        }
    }
    bool f = false;
    if(c == a+b)
        f = true;
    for(int q = 0 ; q < 9 ; q++)
    {
        for(int i = 0 , j = d+q ; i < a && j >= -1 ; i++ , j--)
        {
            if(j < b && j >= 0)
                H += (x[i]-'0')*(y[j]-'0');
        }
        cout << H << endl;
        v.push_back(H);
        H = 0;
    }
    K = v[v.size()-1];
    for(int i = v.size()-2 ; i >= 0  ; i--)
    {
        K = (K+v[i]*10);
        K /= 10;
    }

    cout << ((f)?K/10:K%10) << endl;
    
    return 0;
}