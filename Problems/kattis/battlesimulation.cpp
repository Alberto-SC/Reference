#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    char ans[s.size()];
    int j = 0;
    for(int i = 0;i<s.size();i++){
        if((s[i]-'A')+(s[i+1]-'A')+(s[i+2]-'A') == 29){ans[j++] = 'C';i+=2;}
        else if(s[i] == 'R')ans[j++] = 'S';
        else if(s[i] == 'B')ans[j++] = 'K';
        else if(s[i] == 'L')ans[j++] = 'H';
    }
    for(int i = 0;i<j;i++)
        cout<<ans[i];
    
    return 0;
}