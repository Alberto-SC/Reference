#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,x,y;
    cin>>n>>x>>y;
    if(n>y)return cout<<"-1"<<endl,0;
    if(n == y){
        if(n >= x){
            for(int i = 0;i<n;i++)cout<<1<<endl;
        }
        else if(x> n)return cout<<"-1"<<endl,0;
    }
    else if(((n-1)+((y-(n-1))*(y-(n-1))))>=x){
        cout<<y-(n-1)<<endl;
        for(int i = 0;i<n-1;i++){
            cout<<1<<endl;
        }
    }
    else cout<<"-1"<<endl;
    return 0;
}