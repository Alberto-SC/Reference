#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%3 == 0)cout<<n-2<<" "<<1<<" "<<1<<endl;
    if(n%3 == 1|| n%3 == 2)cout<<n-3<<" "<<2<<" "<<1<<endl;
    return 0;
}