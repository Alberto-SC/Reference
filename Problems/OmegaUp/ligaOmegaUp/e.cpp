#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool> b(1600,false);
    b[580] = true;
    b[980] = true;
    b[1190] = true;
    b[1250] = true;
    b[1420] = true;
    if(n<540)return cout<<"error"<<endl,0;
    else if(n>1520)return cout<<"error"<<endl,0;
    int d1 = 0;
    int d2 = 0;
    if(b[n]){
        if(n==580)return cout<<"adelante "<<400<<endl,0;
        if(n==1420)return cout<<"atras "<<170<<endl,0;
        for(int i = n+1;i<=1420;i++){
            if(b[i])break;
            d1++;
        }
        for(int i = n-1;i>=580;i--){
            if(b[i])break;
            d2++;
        }
        if(d1<d2)return cout<<"adelante "<<d1+1<<endl,0;
        else return cout<<"atras "<<d2+1<<endl,0;
    }
    
    for(int i = n;i<=1420;i++){
        if(b[i])break;
        d1++;
    }
    for(int i = n;i>=580;i--){
        if(b[i])break;
        d2++;
    }
    if(n<580)cout<<"adelante "<<d1<<endl;
    else if(n>1420)cout<<"atras "<<d2<<endl;
    else if(d1<d2)cout<<"adelante "<<d1<<endl;
    else cout<<"atras "<<d2<<endl;
    return 0;
}