#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli a,b;
    while(1){
        cin>>a>>b;
        if(a == 0 && b == 0)break;
        if(b%4 == 0){
            cout<<a<<endl;
        }
        else if(b%4 ==1){
            cout<<a<<"i"<<endl;
        } 
        else if(b%4 ==2){
            cout<<-a<<endl;
        }
        else{
            cout<<-a<<"i"<<endl;
        }
    }
    return 0;
}  

