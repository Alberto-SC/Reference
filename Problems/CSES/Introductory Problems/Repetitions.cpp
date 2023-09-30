#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){__
    string s;
    cin>>s;
    int n = s.size();
    int c = 1,mx = 0;
    for(int i = 1;i<n;i++){
        if(s[i]!=s[i-1])
            c = 1;
        else c++;
        mx =max(mx,c);
    }
    mx = max(mx,c);
    cout<<mx<<endl;
    return 0;
}