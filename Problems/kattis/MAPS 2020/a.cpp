#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    set<string> ss;
    for(int i = 0;i<n;i++){
        scanf("%[\n]",s);
        for(int i = 0;i<s.size();i++){
            if(s[i]>='A' || s[i]<='Z'){
                s[i] = s[i]+32;
            }
            if(s[i] = '-')s[i] = ' ';
        }
        ss.insert(s);
    }
    cout<<ss.size()<<endl;
    return 0;
}