#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,ai;
    cin>>n;
    vector<bool> lvl(n+1,false);
    cin>>x;
    for(int i = 0;i<x;i++)
        cin>>ai,lvl[ai] = true;
    cin>>x;
    for(int i = 0;i<x;i++)
        cin>>ai,lvl[ai] = true;
    for(int i = 1;i<=n;i++)
        if(!lvl[i])return cout<<"Oh, my keyboard!"<<endl,0;
    cout<<"I become the guy."<<endl;
    return 0;
}