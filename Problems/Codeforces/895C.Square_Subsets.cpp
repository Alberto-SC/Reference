#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
const int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
typedef long long int lli;
const lli mod = 1e9 +7;
lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
struct basisxor{
    int base[30];
    int sz = 0;
    basisxor(){
        for(int i = 0;i<30;i++)base[i] = 0;
    }
    void add(int x){
        while(x!= 0 && base[31-__builtin_clz(x)]!= 0){
            x^=base[31-__builtin_clz(x)]; 
        }
        if(x== 0)return;
        base[31-__builtin_clz(x)] = x;
        sz++;
    }
};

int main(){
    int n;
    cin>>n; 
    basisxor bs;
    int ones = 0;
    for(int i = 0;i<n;i++){
        int aux;
        cin>>aux;
        if(aux== 1)continue;
        int mask = 0;
        for(int j = 0;j<19;j++){
            int cont = 0;
            
            while(aux%primes[j] == 0){
                cont++;
                aux/=primes[j];
            }
            if(cont&1)
                mask|=1<<j;
        }
        bs.add(mask);
    }
    cout<<mod_pow(2,n-bs.sz)-1<<endl;
    return 0;
}