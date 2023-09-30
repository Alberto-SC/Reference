#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long

map<int,int> mp;

int solve(int n){
    if(n==0)return n;
    if(mp.count(n))return mp[n];
    int div = solve(n/2)+solve(n/3)+solve(n/4);
    mp[n] = max(n,div);
    return mp[n];
}
signed main(){
    int n;
    while(cin>>n){
        cout<<solve(n)<<endl;
    }
    return 0;
}
