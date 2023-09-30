#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod =  11092019;

// lli calc
int main(){
    string s;
    cin>>s;
    vector<int> b(26,1);
    for(int i = 0;i<s.size();i++)
        b[s[i]-'a']++;
    lli ans = 1;    
    for(int i = 0;i<26;i++)
        ans = (ans*b[i])%mod;

    cout<<ans<<endl;
    return 0;
}