#include <bits/stdc++.h>
using namespace std;
map<string,set<string>> mp;

int check(set<string> st,string s){
    vector<string> v;
    v.push_back(s);
    for(auto c:st){
        v.push_back(c);
    }
    vector<int> p(v.size(),1);
    for(int i = 0;i<v.size();i++){
        string current = v[i];
        for(int j = i+1;j<v.size();j++){
            if(p[j]== 0)continue;
            if(mp[current].find(v[j])== mp[current].end())p[i] = 1;
        }
    }
    int total = accumulate(p.begin(),p.end(),0);
    return total;
}

int dist(string a,string b){
    int d = 0;
    for(int i = 0;i<a.size();i++){
        if(a[i]!= b[i])d++;
    }
    return d;
}


int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    for(auto &c:s)cin>>c;
    sort(s.begin(),s.end());
    cout<<endl;
    for(auto c:s)cout<<c<<endl;

    // for(int i = 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         if(i == j)continue;
    //         if(dist(s[i],s[j]) != 2)mp[s[i]].insert(s[j]);
    //     }
    // }
    // for(auto c:mp){
    //     cout<<c.first<<" ";
    //     for(auto d:c.second)cout<<d<<" ";
    //     cout<<endl;
    // }
    // int ans = 0;
    // for(int i = 0;i<n;i++){
    //     ans = max(check(mp[s[i]],s[i]),ans);
    // }

    // cout<<ans<<endl;
    return 0;
}