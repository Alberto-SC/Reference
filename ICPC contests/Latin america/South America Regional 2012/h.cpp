#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        cout<<"NY"[n%6== 0]<<endl;
    }
    return 0;
}