#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,j1,j2,max1 = -100,max2 = -100;
    cin>>n;  
    for(int i = 0;i<n;i++){
        cin>>j1>>j2;
        if(j1>=j2 && j1-j2>max1)max1 = j1-j2;
        else if(j2>j1 && j2-j1>max2)max2 = j2-j1;
    }
    if(max1>max2)cout<<1<<" "<<max1;
    else cout<<2<<" "<<max2;
    return 0;
}