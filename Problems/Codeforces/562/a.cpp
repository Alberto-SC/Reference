#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,x,b,y,moved = 0,movV = 0;
    cin>>n>>a>>x>>b>>y;
    for(int i = a,j = b;true;i++,j--){
        moved++;
        movV++;
        if(i ==n+1)i = 1;
        if(j == 0)j = n;
        if(i == j)return cout<<"YES"<<endl,0;
        if(i == x||j == y)break;
    }
    cout<<"NO"<<endl;
    return 0;
}