#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        int ans = 0;
        int last = 0;
        if(s[0]=='0')last = 1;
        for(int i= 0;i<n-1;i++){
            if(s[i]== '0'){
                if(last ==1)ans = i+1;
                cout<<ans<<" ";
                last = 0;
            }
            else {
                if(last == 0)ans = i+1;
                cout<<ans<<" ";
                last = 1;
            }
        }
        cout<<endl;
    }
    return 0;
}