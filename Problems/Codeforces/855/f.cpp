#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<string> s(n);
        for(auto &c:s)cin>>c;
        vector<int> mp((1<<26)+7); 
        vector<int> v(n);
       
        long long ans = 0;
        for(int c = 0;c<26;c++){
            int need = (1<<26)-1;
            need -= 1<<c;
            for(int k = 0;k<n;k++){
                int x = 0;
                int have = 0;
                for(int j = 0;j<s[k].size();j++){
                    int c = s[k][j]-'a';
                    x^=(1<<c);
                    have |= (1<<c);
                }   
                if((have>>c)&1)continue;
                ans+=mp[need^x];
                mp[x]++;
            }
            for(int k = 0;k<n;k++){
                int x = 0;
                int have = 0;
                for(int j = 0;j<s[k].size();j++){
                    int c = s[k][j]-'a';
                    x^=(1<<c);
                    have |=(1<<c);
                }   
                if((have>>c)&1)continue;
                mp[x]--;
            }


        }
        cout<<ans<<endl;
    }
    
}

