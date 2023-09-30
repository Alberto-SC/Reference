#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
vector<lli> fibo;
int main(){
    lli mx =(lli)1<<63,n;
    lli fib1 =1,fib2 = 1,fib3=1;
    fibo.push_back(fib1);
    fibo.push_back(fib2);
    while(fib3<=mx){
       fib3 = fib1+fib2;
       fibo.push_back(fib3);
       fib1 = fib2;
       fib2 = fib3;
    }
    cin>>n;
    int index = lower_bound(fibo.begin(),fibo.end(),n)-fibo.begin();
    if(fibo[index]== n)cout<<index+1;
    else cout<<-1<<endl;
    return 0;
}