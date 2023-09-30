#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
    int n;
    string s,t ="",u = "";
    cin>>s;
    n = s.size();
    vector<int> c(26);
    for(int i = 0;i<n;i++)
        c[s[i]-'a']++;
    for(int i = 0;i<n;i++){
        t+=s[i];
        c[s[i]-'a']--;
        while(t.size()){
            bool flag = true;
            int id = t.back()-'a';
            for(int j = 0;j<id;j++){
                if(c[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                u+=t.back();
                t.pop_back();
            }
            else break;
        }
    }
    cout<<u<<endl;
}