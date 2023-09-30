#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int is_pow(lli x){
    lli r = 1;
    int cont= 0;
    while(r<x){
        r<<=1;
        cont++;
    }
    if(r ==x)return cont;
    return -1;
}

int main(){__
    lli t ,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;  
        if(m>n)swap(n,m);
        lli x = n/m;
        int cont = 0;
        if(is_pow(x)== -1 || n%m != 0)cout<<-1<<endl;
        else {
            int pot = log2(x);     
            // cout<<pot<<endl;       
            cont+=pot/3;
            if(pot%3== 0)cout<<cont<<endl;
            else cout<<cont+1<<endl;
        }
    }
    return 0;
}