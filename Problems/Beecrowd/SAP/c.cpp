#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


signed main(){__
    string s;
    cin>>s;
    int n = s.size();
    string rem ="";
    for(int i = 0;i<n;i++){
        if(i%2==0)rem.push_back(s[i]);
        else cout<<s[i];
    }
    reverse(rem.begin(),rem.end());
    cout<<rem<<endl;
}   