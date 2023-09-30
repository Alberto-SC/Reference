#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n ;
    map<string,int> mp ;
    char type ;
    for (int i=0 ; i<n ; i++){
        cin>>type;
        string s;
        string b = string(18,'0');
        cin>>s;
        for (int j=s.length()-1; j>=0; j--){
            if((s[j]-'0')%2==0)
                b[s.length()-1-j]='0';
            else
                b[s.length()-1-j]='1';
        }
        // cout<<b<<endl;
        if (type=='+') mp[b]++;
        else if (type=='-') mp[b]--;
        else cout << mp[b] << endl ;
    }
    return 0;
}