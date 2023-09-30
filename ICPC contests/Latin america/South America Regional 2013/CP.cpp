#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll bitsOn(ll x)
{
    ll ans = 0;
    for(int i = 0 ; i < 63 ; i++)
        if(((1LL<<i)&x)!= 0)
            ++ans;
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   ll x , f , ans = 0 , ant = 0;
   cin >> f;
   for(int i = 1 ; i <= f ; i++)
    {
        if(bitsOn(i) == 1)
        {
            cout << ans-ant << '\n';
            ant += ans;
            ans = 0;
        }
        ans += bitsOn(i);
    }
    return 0;
}