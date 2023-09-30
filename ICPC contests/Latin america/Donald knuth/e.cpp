#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1)x = (a*x);
        a = (a*a);
        b>>=1;
    }
    return x;
}

int main(){    
    lli n,m;
    cin>>m;
    string s;
    vector<lli  > c(20);
    for(lli  i = 0;i<m;i++){
        cin>>s;
        for(lli  i = s.size();i<19;i++){
            c[i]+= mod_pow(9,i-s.size()); 
        }
    }
    vector<lli > ac(20);
    ac[0] = 0;
    for(int  i = 1jnj;i<20;i++){
        ac[i] = c[i]+ac[i-1];
    }
    for(auto d:c)cout<<d<<" ";
    cout<<endl;
    for(auto d:ac)cout<<d<<" ";
    cout<<endl;
    cin>>n;
    lli x = n;
    lli  cont = 1;
    while(n){
        n/=10;
        x+=ac[cont];
        cont++;
    }
    cout<<x<<endl;
    return 0;
}