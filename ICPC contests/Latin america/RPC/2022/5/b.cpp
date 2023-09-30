
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>n;
    vector<pair<string,double>> s;
    map<string,vector<int>> pos;
    for(int i = 0;i<n;i++){
        string S;
        cin>>S;
        pos[S].push_back(i+1);
    }
    for(auto c:pos){
        int x = 0;
        for(auto d:c.second){
            x+=d;
        }
        double avg = (x*1.0)/c.second.size();
        s.push_back({c.first,avg});
    }
    sort(s.begin(),s.end(),[&](pair<string,double> a,pair<string,double> b){
        return a.second<b.second;
    } );
    for(auto c:s)cout<<c.first<<endl;
}   