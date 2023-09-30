#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<bool> b(n+1,true);
    int fib1 =1,fib2 = 1,fib3=1;
    b[1] = false;
    b[2] = false;
    while(fib3<=n){
       fib3 = fib1+fib2;
       b[fib3] = false;
       fib1 = fib2;
       fib2 = fib3;
    }
    for(int i = 4;i<n;i++){
        if(b[i])cout<<i<<" ";
    }
    return 0;
}