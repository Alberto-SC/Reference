#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i = 0;
    while(s[i]<='9' && s[i]>='0'){
        i++;
    }
    if (i == 0)cout<<-1<<endl;
    else cout<<s.substr(0,i);
    return 0;
}