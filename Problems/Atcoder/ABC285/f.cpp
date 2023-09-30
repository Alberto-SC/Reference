#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
    int T = 1,n;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        vector<int> f(26);
        set<int> st[26];
        for(int i = 0;i<n;i++){
            st[s[i]-'a'].insert(i);
        }
        int q;
        cin>>q;
        while(q--){
            int t,x,a,b;
            char c;
            cin>>t;;
            if(t ==1){
                cin>>x>>c;
                x--;
                f[s[x]-'a']--;
                f[c-'a']++;
                st[s[x]-'a'].erase(x);
                s[x] = c;
                st[c-'a'].insert(x);
            }
            else{
                cin>>a>>b;
                a--,b--;
                bool first = true,flag = true;
                while(1){
                    int nxt = n+7;
                    for(int i = 0;i<26;i++){
                        if(i == (s[a]-'a'))continue;
                        auto it = st[i].lower_bound(a);
                        int mn;
                        if(it == st[i].end())continue;
                        else mn = *it;
                        nxt = min(nxt,mn);
                    }
                    cou
                    if(nxt>b){
                        break;
                    }

                    if(s[nxt]<s[a]){
                        flag = false;
                    }
                    if(s[nxt]>s[a] && !first){
                        int len = nxt-a;
                        if(f[s[a]-'a']!= len){
                            flag = false;
                        }
                        for(int i = (s[a]-'a')+1;i<(s[nxt]-'a');i++){
                            if(f[i])flag = false;
                        }
                    }
                    else first = false;
                    if(!flag)break;
                }

                if(flag)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;

            }
        }
    }
    return 0;
}