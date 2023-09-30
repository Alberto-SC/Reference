#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int f = 0;
        for(int i =0;i<n;i++){
            if(s[i]== ',' && !f)s[i] = '.';
            if(s[i]== '"')f^=1;
        }
        cout<<s<<endl;
    }
    return 0;
}