#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){
    int n,q;
    cin>>n;
    vector<string> s(n);
    for(auto &c:s)cin>>c;
    
    sort(s.begin(),s.end());
    map<string,int> mp;
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = 0;j<s[i].size();j++){
            sum+=(s[i][j]-'A')+1;
        }
        mp[s[i]] =sum*(i+1);
    }
    cin>>q;
    while(q--){
        string t;
        cin>>t;
        cout<<mp[t]<<endl;
    }
    return 0;
}
