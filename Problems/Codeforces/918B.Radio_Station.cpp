#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s,ip;
    cin>>n>>m;
    map<string,string> mp;
    for(int i = 0;i<n;i++){
        cin>>s >>ip;
        mp[ip] = s;
    }
    for(int i = 0;i<m;i++){
        cin>>s>>ip;
        ip.pop_back();
        cout<<s<<" "<<ip<<"; #"<<mp[ip]<<endl;
    }
    return 0;
}