#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    string v,s,x;
    int n;
    cin>>v;
    cin>>s;
    cin>>n;

    vector<int> pos[26];
    for(int i = 0;i<s.size();i++){
        pos[s[i]-'a'].push_back(i);
    }

    int idx = -1,L= 0;
    while(1){
        int mx = -1;
        for(auto c:v){
            int i = c-'a';
            int id = upper_bound(pos[i].begin(),pos[i].end(),idx)-pos[i].begin();
            if(id==pos[i].size())
                mx = s.size();
            else
                mx = max(mx,pos[i][id]);
        }
        L++;
        if(mx == s.size())break;
        idx = mx;
    }
    for(int i = 0;i<n;i++){
        cin>>x;
        if(x.size()!=L)cout<<0<<endl;
        else{
            idx = -1;
            bool flag = false;
            for(int j = 0;j<x.size();j++){
                int k = x[j]-'a';
                int id = upper_bound(pos[k].begin(),pos[k].end(),idx)-pos[k].begin();
                if(id== pos[k].size()){
                    flag = true;
                    break;
                }
                else idx = pos[k][id];
            }
            if(flag)cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}