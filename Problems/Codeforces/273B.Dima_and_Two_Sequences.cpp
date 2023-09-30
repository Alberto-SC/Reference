#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,m,ai;
    cin>>n;
    map<pair<lli,lli>,int> mp;
    vector<lli> c;
    for(lli i = 0;i<n;i++){
        cin>>ai;
        c.push_back(ai);
        mp[{ai,i}]++;
    }
    for(lli i = 0;i<n;i++){
        cin>>ai;
        c.push_back(ai);
        mp[{ai,i}]++;
    }
    cin>>m;
    lli d2 = 0;
    for(auto c:mp){
        if(c.second==2)d2++;
    }
    sort(c.begin(),c.end());
    // for(auto d:c)cout<<d<<" ";
    // cout<<endl;
    lli ans = 1;
    for(lli i = 0;i<2*n;){
        lli j = i+1;
        while(j<2*n && c[j] == c[i])j++;
        // cout<<j-i<<" "<<j<<" "<<i<<endl;
        for(lli k = 1;k<=j-i;k++){
            lli p = k;
            while(p%2 == 0 && d2){
                d2--;
                p/=2;
            }
            (ans*=p)%=m;
        }
        i = j;
    }
    cout<<ans<<endl;
    return 0;
}