#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
lli subject = 7;
lli mod = 20201227;
int main(){
    lli n1,n2;
    cin>>n1>>n2;
    int loop1 = 0,loop2 = 0;
    lli current = 1;
    while(current != n1){
        (current*=subject)%=mod;
        loop1++;
    }
    current = 1;
    while(current != n2){
        (current*=subject)%=mod;
        loop2++;
    }
    cout<<loop1<<" "<<loop2<<endl;
    lli key1 = 1,key2 = 1;
    for(int i = 0;i<loop2;i++){
        (key1*=n1)%=mod;
    }
    for(int i = 0;i<loop1;i++){
        (key2*=n2)%=mod;
    }
    cout<<key1<<" "<<key2<<endl;
}  

