#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<s.size()<<endl;
    int n = s.size();
    int cont = 0;
    for(int i = 0;i<n;i++){
        if(s[i] == 'a'|| s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'
        ||s[i] == 'A'|| s[i] == 'E' || s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U')cont++;
    }
    cout<<cont<<endl;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}