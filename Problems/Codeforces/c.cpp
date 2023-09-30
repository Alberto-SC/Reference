#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int k = x-y;
    if(k>0 && z<k)return cout<<"+"<<endl,0;
    if(k<0 && k+z<0)return cout<<"-"<<endl,0;
    if(k == 0 && z == 0)return cout<<0<<endl,0;
    cout<<"?"<<endl;
    return 0;
}