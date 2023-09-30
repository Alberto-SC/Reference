#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    set<string> ss;
    vector<string> s(n);
    string palindrome = "";
    for(int i = 0;i<n;i++){cin>>s[i];ss.insert(s[i]);}
    for(int i = 0;i<n;i++){
        bool flag = true;
        for(int j = 0;j<m;j++)
           if(s[i][j] != s[i][(m-1)-j]){flag = false;break;}
        if(flag)palindrome = s[i],ss.erase(palindrome);
    }
    string ans = "";
    for(int i = 0;i<n;i++){
        string search = s[i];
        reverse(search.begin(),search.end());
        if(ss.find(search)!= ss.end()){
            ans+=s[i];
            ss.erase(s[i]);
            ss.erase(search);
        }
    }
    int i = 0;
    string aux = ans;
    reverse(aux.begin(),aux.end());
    ans += aux;
    if(palindrome.size()){
        ans = ans.substr(0,ans.size()/2)+palindrome+ans.substr(ans.size()/2);
    }
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}