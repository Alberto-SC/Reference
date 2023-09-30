#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p1,p2,match = 0;
    string a,b;
    map<string,set<int>> mp;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>p1>>p2>>a>>b;
        mp[a].insert(p1);
        mp[b].insert(p2);
        if(a==b){mp.erase(mp.find(a));match++;}
    }
    int ans  = 0;
    if(match+mp.size() == n/2)
        cout<<mp.size()<<endl;
    else{
        for(auto c:mp){
            if(c.second.size() == 2)ans++;
        }
        if(ans +match == (n/2)-1)ans++;
        cout<<ans<<endl;
    }
    return 0;
}