#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
typedef unsigned long long int ull;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


lli factors[100];
int fcont;

lli bin_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1)x *=a;
        a*=a;
        b>>=1;
    }
    return x;
}

void factorize(lli n){
    fcont = 0;
    while(n%2 ==0){
        n/=2;
        factors[fcont++]=2;
    }
    for(int i = 3;i<=sqrt(n);i++){
        while(n%i==0){
            n/=i;
            factors[fcont++] = i;
        }
    }
    if(n>1){
        factors[fcont++] = n;
    }
}
int main(){__
    lli t = 1,n,p,q;
    cin>>t;
    while(t--){
        cin>>p>>q;
        if(q>p || p%q)cout<<p<<endl;
        else {
            factorize(q);
            map<int,int> mp1;
            for(int i = 0;i<fcont;i++)
                mp1[factors[i]]++;
            lli ans = p;
            lli mn = 1e18;
            for(auto c:mp1){
                int cont = 0;
                while(p%c.first==0){
                    p/=c.first;
                    cont++;
                }
                mn = min(mn,bin_pow(c.first,(cont-c.second)+1));
            }
            ans/=mn;
            cout<<ans<<endl;
        }
    }
    return 0;
}

