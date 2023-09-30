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
        string ans = string(n,'0');
       	if(s[0]!='9'){
            for(int i=0;i<n;i++)
                cout<<char('9'-s[i]+'0');
            cout<<endl;
        }
        else{
            int c=0;
            for(int i=n-1;i>=0;i--){
                int x=1-c-s[i]+'0';
                if(x<0){
                    c=1;
                    x+=10;
                }else{
                    c=0;
                }
                ans[i]=x+'0';
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}