#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string type,name,igual,neww,assign,var1,var2;
    map<string,int>mp;
    int key = 0;
    for(int i = 0;i<n;i++){
        cin>>type>>name>>igual>>neww;
        getline(cin,assign);
        mp[name]= key++;
    }
    vector<int> buck(key,1);
    // for(auto c:mp)cout<<c.first<<" "<<c.second<<endl;
    // cout<<key<<endl;
    for(int i = 0;i<m;i++){
        cin>>var1>>igual>>var2;
        // cout<<var1<<" "<<var2<<endl;
        // cout<<mp[var1]<<" "<<mp[var2]<<endl;
        buck[mp[var1]]--;
        buck[mp[var2.substr(0,var2.size()-1)]]++;
    }
    int ans = 0;
    for(int i = 0;i<key;i++)if(buck[i]>0)ans++;
    cout<<ans<<endl;
    return 0;
}
