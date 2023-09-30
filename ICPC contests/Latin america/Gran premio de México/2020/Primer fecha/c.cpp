#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007; 
vector<int> p(maxn);
vector<int> sz(maxn,1);
vector<int> mn(maxn);
vector<string> l(maxn);

int get_root(int u){
    return u==p[u]?u:p[u] = get_root(p[u]);
}

void union_sz(int u,int v){
    u = get_root(u);
    v = get_root(v);
    if(u ==v)return;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    if(l[v].size()== l[u].size()){
        if(l[v]<l[u])
            l[u] = l[v];
    }
    else if(l[v].size()<l[u].size())
        l[u] = l[v];
}

int main(){
    int n;
    iota(p.begin(),p.end(),0);
    cin>>n;
    string s,t;
    int key = 0;
    vector<pair<string,string>> edges;
    map<string,int> mp;
    for(int i = 0;i<n ;i++){
        cin>>s>>t;
        edges.push_back({s,t});
        if(!mp.count(s))
            mp[s] = key++;
        if(!mp.count(t))
            mp[t] = key++;
    }
    for(auto c:mp){
        l[c.second] = c.first;
    }
    for(int i = 0;i<n;i++){
        union_sz(mp[edges[i].first],mp[edges[i].second]);
    }
    // cout<<"hi"<<endl;
    getline(cin,s);
    getline(cin, s);
	istringstream in(s);
	vector<string> words;
	string w;
	while(getline(in, w, ' ')){
		words.push_back(w);
	}

    for(int i  = 0;i<words.size();i++){
        if(!mp.count(words[i]))
            cout<<words[i];
        else {
            cout<<l[get_root(mp[words[i]])];
        }
        if(i!= words.size()-1)cout<<" ";
    }
    cout<<endl;
    return 0;
}      
