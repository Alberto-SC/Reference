#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>x;
        if(x)return cout<<"HARD"<<endl,0;
    }
    cout<<"EASY"<<endl;
    return 0;
}