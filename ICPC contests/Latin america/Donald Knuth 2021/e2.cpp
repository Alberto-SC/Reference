#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
 
vector<int> moves(20);
int n,s;
int bruta(int x){
    bitset<3> bsx(x);
    // cout<<"->"<<bsx<<endl;
    int cont = 0;
    while(__builtin_popcount(x)){
        int y = __builtin_popcount(x);
        x^=1<<(n-y);
        // bitset<3> bs(x);
        // cout<<bs<<endl;
        cont++;
    }
    s+=cont;
    // cout<<cont<<endl;
    moves[cont]++;
}
 
signed main(){__
    cin>>n;
    int d = 0;
    for(int i = 0;i<(1<<n);i++){
        d++;
        bruta(i);
    }
    int gcd = __gcd(s,d);
    s/=gcd;
    d/=gcd;
    cout<<s<<"/"<<d<<endl;
    return 0;
}  