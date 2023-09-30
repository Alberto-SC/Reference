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
        int x = 0,y = 0;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(s[i]=='L'){
                x--;
            }
            else if(s[i]=='R'){
                x++;
            }
            else if(s[i]== 'U'){
                y++;
            }
            else {
                y--;
            }
            if(x == 1 && y == 1)flag = true;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}