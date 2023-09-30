#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long k,m,fib,fib1,aux,ans,ind = 1l;
    while(cin>>k>>m){
        fib1=1;
        fib= 0;
        ind = 1;
        while(fib1%m!= 0){
            aux = fib1;
            fib1 = fib+fib1;
            fib = aux;
            ind++;
        }
        ans = ind*k;
        cout<<ans<<endl;
    }
    cout<<1%3;
    return 0;
}
