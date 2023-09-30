#include <bits/stdc++.h>
using namespace std;

int main (){
    long long int n,m,a,cont = 0,mod = 0;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a;
        if(mod){
            mod+= a;
            if(mod >= m) cont += mod/m,mod %=m;
            else mod = 0,cont++;
        }
        else{
            mod += a;
            if(mod >= m) cont += mod/m, mod %=m; 
        }
    }   
    if(mod)cont++;
    cout<<cont<<endl;
    return 0;
}