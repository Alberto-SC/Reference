#include <bits/stdc++.h>
using namespace std;

map<string,vector<pair<string,int>>> graph;

map<string,bool> vis;
int cont = 0;
void dfs(string u,int c = 1){
    vis[u] = true;
    for(auto v:graph[u]){
        // if(!vis[v.first])
        dfs(v.first,c*v.second);
    }
    cout<<u<<" : "<<c<<endl;
    cont+=c;
}
int main(){
    string s;
    vector<string> answer;
    int ans = 0;
    while(getline(cin,s)){
        istringstream in(s);
        string w;
        vector<string> bags;
        while(getline(in, w, ' ')){
            bags.push_back(w);
        }
        string color = bags[0]+"_"+bags[1];
        int idx = 4;
        while(idx<bags.size() && bags[idx]!= "no"){
            int c = stoi(bags[idx]);
            if(bags[idx+1].back()==13)bags[idx+1].pop_back();
            if(bags[idx+2].back()==13)bags[idx+2].pop_back();
            string color2 = bags[idx+1]+"_"+bags[idx+2];
            idx+=4;
            cout<<color<<" -> "<<color2<<endl;
            graph[color].push_back({color2,c});
        }
    }
    dfs("shiny_gold");
    cout<<cont-1<<endl;
    return 0;
}