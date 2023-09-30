#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        string s,t;
        cin>>s>>t;
        int id = 0;
        while(s[id]==t[id]){
            id++;
        }
        cout<<id+1<<endl;
    }
    return 0;
}