#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int n;
    cin>>n;
    if(n== 2 || n== 3)return cout<<"NO SOLUTION"<<endl,0;
    for(int i = 2;i<=n;i+=2)cout<<i<<" ";
    for(int i = 1;i<=n;i+=2)cout<<i<<" ";
    cout<<endl;
    return 0;
}