#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    string s;
    map<string,lli>mp;
    vector<lli> b(26);
    for(lli i = 0;i<n;i++){
        cin>>s;
        b[s[0]-'A']++;
        mp[s]++;
    }   
    lli ans = 0;
    for(lli i = 0;i<26;i++){
        ans+= b[i]*(b[i]-1);
    }
    for(auto v:mp)
        ans-=v.second*(v.second-1);
    
    cout<<ans<<endl;
    return 0;
}