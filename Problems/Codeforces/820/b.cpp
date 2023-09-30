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
        string ans = "";
        for(int i = n-1;i>=0;i--){
            if(s[i]== '0'){
                int x = (s[i-1]-'0')+((s[i-2]-'0')*10);
                ans.push_back(char((x+'a')-1));
                i-=2;
            }
            else ans.push_back(char(((s[i]-'0')+'a')-1));
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}