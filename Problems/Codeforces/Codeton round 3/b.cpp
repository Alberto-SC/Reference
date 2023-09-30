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
        vector<int> ac(n);
        ac[0] = s[0]=='1';
        vector<int> pos[2];
        for(int i = 1;i<n;i++){
            ac[i] = ac[i-1]+(s[i]=='1');
        }
        for(int i = n-1;i>=0;i--){
            pos[s[i]-'0'].push_back(i);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='0'){
                int nextOne;
                if(pos[1].size())
                    nextOne = pos[1].back();
                else nextOne = n;
                int x = nextOne-i;
                int len = n-i;
                int o = ac[n-1]-(i?ac[i-1]:0);
                int z = len-o;
                ans = max({x*x,o*z,ans});
                pos[0].pop_back();
            }
            else{
                int nextZero;
                if(pos[0].size())
                    nextZero = pos[0].back();
                else nextZero = n;

                int x = nextZero-i;
                int len = n-i;
                int o = ac[n-1]-(i?ac[i-1]:0);
                int z = len-o;
                ans = max({x*x,o*z,ans});
                pos[1].pop_back();
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}