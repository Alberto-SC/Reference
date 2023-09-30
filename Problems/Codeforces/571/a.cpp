#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(1){
        int c = n,sum = 0;
        while(c){
            sum+= c%10;
            c/=10;
        }
        if(sum%4 == 0){
            cout<<n;
            break;
        }
        n++;
    }
}