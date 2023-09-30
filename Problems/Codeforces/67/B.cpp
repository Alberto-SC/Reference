#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string s;
    cin>>n>>s>>m;
    string name;
    vector<int> pos[26];
    for(int i = 0;i<n;i++){
        pos[s[i]-'a'].push_back(i);
    }
    for(int i = 0;i<m;i++){
        cin>>name;
        vector<int> num(26,0);
        int mx = -1;
        for(int j =0 ; j < name.size();j++){
            mx = max(pos[name[j]-'a'][num[name[j]-'a']],mx);
            num[name[j]-'a']++;
        }
        cout<<mx+1<<"\n";
    }
    return 0;
}