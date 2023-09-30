#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>n;
    string s;
    map<string,int> mp;
    for(int i = 0;i<n;i++){
        cin>>s;
        mp[s]++;
    }
    int mx = -1;
    int sum = 0;
    string ss;
    for(auto c:mp){
        sum+=c.second;
        if(c.second>mx){
            mx = c.second;
            ss = c.first;
        }
    }
    if(mx>(sum-mx))return cout<<ss<<endl,0;
    else cout<<"NONE"<<endl;
    return 0;
}

