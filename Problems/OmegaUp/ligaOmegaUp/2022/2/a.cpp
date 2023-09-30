#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


bool sub(string s,string t){
    bool flag = false;
    if(t.size()>s.size())return false;
    for(int i = 0;i<=s.size()-t.size();i++){
        bool f = true,en = false;
        int idx = 0;
        while(idx<t.size() && t[idx]==s[i+idx])idx++;
        if(idx==t.size())flag = true;
    }
    return flag;
}

string getString(string s,string t){
    for(int i = t.size()-1;i>=0;i--){
        int idx = s.size()-1;
        bool flag = true;
        for(int j = 0;j<i;j++){
            if(idx<0 || t[(i-1)-j]!=s[idx--])flag= false;
        }
        if(flag)return s+t.substr(i);
    }
    return "";
}

signed main(){__
    int n;
    cin>>n;
    vector<string> s(n);
    for(auto &c:s)cin>>c;
    sort(s.begin(),s.end());
    string t = "";
    vector<bool> used(n);
    int cont = n;
    cout<<sub("ABA","BAB")<<endl;
    while(cont){
        vector<string> pos;
        vector<int> idx;
        cout<<"T-> "<<t<<endl;
        for(int i = 0;i<n;i++){
            if(!used[i] && sub(t,s[i])){
                used[i] = true,cont--;
                cout<<"SUB "<<s[i]<<endl;
            }
        }
        for(int i = 0;i<n;i++){
            if(!used[i])pos.push_back(getString(t,s[i])),idx.push_back(i);
        }
        if(!pos.size())break;
        int mnsz =1e9;
        for(int i = 0;i<pos.size();i++){
            mnsz =min(mnsz,(int)pos[i].size());
        }
        string mn = "{";
        int id =-1;
        for(int i = 0;i<pos.size();i++){
            if(mnsz == pos[i].size() && pos[i]<mn){
                mn = pos[i];
                id = idx[i];
            }
        }
        used[id] = true;
        cont--;
        t = mn;
    }
    cout<<t<<endl;
    return 0;
}