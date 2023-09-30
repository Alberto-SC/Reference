#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    set<string> ss;
    fflush(stdin);
    for(int i = 0;i<n;i++){
        getline(cin,s);  
        for(int j = 0;j<s.size();j++){
            if(s[j]>='A' && s[j]<='Z'){
                s[j] = (char)((int)s[j]+32);
            }
            if(s[j] == '-')s[j] = ' ';
        }
        ss.insert(s);
    }
    cout<<ss.size()<<endl;
    return 0;
}