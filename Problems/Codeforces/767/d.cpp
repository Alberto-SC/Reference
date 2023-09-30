#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<string> s(n);
        for(auto &c:s)cin>>c;
        map<string,vector<int>> mp; 
        bool flag = false;
        for(int i = 0;i<n;i++){
            string k ="";
            bool palindrome = true;
            for(int j = 0;j<=s[i].size()/2;j++)
                if(s[i][j]!= s[i][(s[i].size()-1)-j])palindrome = false;
            if(palindrome)flag = true;
            mp[s[i]].push_back(i);
        }
        vector<int> ans;
        for(int i = 0;i<n;i++){
            string need = s[i];
            reverse(need.begin(),need.end());
            if(mp.count(need) && mp[need].back()>i) flag = true;
            if(s[i].size()== 2){
                for(int j = 0;j<26;j++){
                    if(mp.count(char(j+'a')+need) && mp[char(j+'a')+need].back()>i)flag = true;
                }   
            }
            else if(s[i].size()==3){
                need = s[i];
                need.pop_back();
                reverse(need.begin(),need.end());
                if(mp.count(need) && mp[need].back()>i)flag = true;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;

}