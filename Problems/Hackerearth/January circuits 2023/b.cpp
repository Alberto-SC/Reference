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
        set<char> st;
        vector<int> f(3);
        for(auto c:s){
            f[c-'0']++;
            st.insert(c);
        }
        vector<int> v;
        for(auto c:st){
            v.push_back(c);
        }

        if(v.size()==1){
            cout<<0<<endl;
            continue;
        }

        int ans = 1e9;
        do{
            string target = "";
            for (auto c:v){
                target+=string(f[c-'0'],c);
            }
            map<pair<int,int>,int> mp;
            int res = 0;
            for(int i = 0;i<n;i++){
                if(s[i]==target[i])continue;
                mp[{s[i]-'0',target[i]-'0'}]++;
            }

            int rem = 0;

            for(auto &c:mp){
                int mn = min(c.second,mp[{c.first.second,c.first.first}]);
                c.second-=mn;
                mp[{c.first.second,c.first.first}] -=mn;
                rem+=c.second;
                res+=mn;
            }
            res+=(rem/3)*2;
            ans = min(ans,res);
            // cout<<target<<" "<<res<<" "<<rem<<endl;
        }while(next_permutation(v.begin(),v.end()));
        cout<<ans<<endl;
    }
    return 0;
}