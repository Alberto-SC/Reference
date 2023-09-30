#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n == 1)cout<<1;
    else if(n ==2)cout<<5;
    else if(n == 3)cout<<13;
    else cout<<13+((n-3)*12)<<endl;
    return 0;
}