#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int rem = 0;
        for(int i = 0;i<s.size();i++){
            rem = (rem*10 + (s[i]-'0'))%20;
        }
        cout<<rem<<endl;
    }
    return 0;
}