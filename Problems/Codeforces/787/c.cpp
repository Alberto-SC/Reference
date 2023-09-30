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
        n = s.size();
        int l=1,r=n;
        for(int i = 0;i<n;i++){
            if(s[i] == '1') l = i+1;
            if(s[i] == '0' && r == n) r = i+1;
        }
        cout<<(r-l)+1<<endl;
    }
    return 0;
}
