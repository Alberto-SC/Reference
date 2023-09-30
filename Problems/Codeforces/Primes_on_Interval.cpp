#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int N =10000000;
int lp[N+1];
int spf[N]; 
void sieve() { 
    spf[1] = 1; 
    for (int i=2; i<N; i++) 
        spf[i] = i; 
    for (int i=4; i<N; i+=2) 
        spf[i] = 2; 
    for (int i=3; i*i<N; i++) { 
        if (spf[i] == i) { 
            for (int j=i*i; j<N; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
int k;
bool Prime_facts(int x){
    int cont = 0; 
    map<int,int> facts; 
    while (x != 1){ 
        facts[spf[x]]++; 
        x = x / spf[x];
        cont++;
        if(cont==k)return true; 
    } 
    return false;
} 
int main(){
    int a,b;
    cin>>a>>b>>k;
    sieve();
    int cont = 0;
    for(int i = a;i<=b;i++){
        cont++;
        if(Prime_facts(i))return cout<<cont<<endl,0;
    }
    cout<<-1<<endl;
    return 0;
}