#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char c;
    vector<bool> b(26);
    for(lli i = 0;i<k;i++){
        cin>>c;
        b[c-'a'] = true;
    }
    lli ans = (n*(n+1))/2;
    int last = -1;
    for(lli j = 0;j<n;j++){
        if(b[s[j]-'a'])continue;
            ans-= (n-j)*(j-last);
            last= j;
    }
    cout<<ans<<endl;
    return 0;
}