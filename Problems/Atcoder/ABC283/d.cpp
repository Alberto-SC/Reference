#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        vector<int> last;
        vector<int> mp(26,-1);
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(s[i] == '(')last.push_back(i);
            else if(s[i] == ')'){
                int ls = last.back();
                for(int j = 0;j<26;j++){
                    if(mp[j]>ls &&mp[j]<i){
                        mp[j] = -1;
                    }
                }
                last.pop_back();
            }
            else{
                if(mp[s[i]-'a']!=-1)flag = false;
                mp[s[i]-'a'] = i;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}