#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int n = s.size(),m = t.size(),ans=0;
    set<char>set1,set0;
    string rev = t;
    reverse(rev.begin(),rev.end());
    for(int i=0; i<=n-m; i++){
        set1.clear();
        set0.clear();
        for(int j = 0;j<m;j++){
            if(t[j] == '0')
                set0.insert(s[i+j]);
            else
                set1.insert(s[i+j]);
        }
        if(set0.size()<=1 && set1.size() <= 1)ans++;
        else{
            set1.clear();
            set0.clear();
            for(int j = 0;j<m;j++){
                if(rev[j] == '0')
                   set0.insert(s[i+j]);
                else
                    set1.insert(s[i+j]);
            }
            if(set0.size()<=1 && set1.size() <= 1)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}