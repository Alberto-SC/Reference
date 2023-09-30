#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string Match[2];
    string a;
    int g[2];
    g[0] = 0;
    g[1] = 0;
    for(int i = 0;i<n;i++){
        cin>>a;
        if(!i){
            Match[0] = a;
            g[0] ++;
        }
        if(a == Match[0])g[0]++;
        else{
            Match[1] = a;
            g[1]++;
        } 
    }
    if(g[0]>g[1])cout<<Match[0];
    else cout<<Match[1];
}