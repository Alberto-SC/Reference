#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

signed main(){
	int t= 1,n;
    map<char,char> mp;
    for(int i = 0;i<26;i++){
        mp[char(i+'A')] = char(i+'A');
    }
    mp['1'] = 'I';
    mp['2'] = 'Z';
    mp['3'] = 'E';
    mp['4'] = 'A';
    mp['5'] = 'S';
    mp['6'] = 'G';
    mp['7'] = 'T';
    mp['8'] = 'B';
    mp['9'] = 'P';  
    mp['0'] = 'O';
    mp[' '] = ' ';
    mp[','] = ',';
    mp['.'] = '.';
    cin>>t;
    string s;
    while(getline(cin,s)){
        n =s.size();
        for(int i = 0 ;i<n;i++)
            cout<<mp[s[i]];
        if(s!= "")
            cout<<endl;
    }
    return 0;
}  
