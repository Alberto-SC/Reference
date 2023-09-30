#include <bits/stdc++.h>
using namespace std;
set<int> graph[27];
vector<int> degree(27,0);
vector<bool> mark(26,false);
bool add_edge(int u, int v){
    graph[u].insert(v);
    graph[v].insert(u);
    degree[v]=graph[v].size();
    degree[u]=graph[u].size();
    if(degree[u]>2 || degree[v]>2)return false;
    return true;
}
void bfs(int u){
    bool *visited = new bool[26];
    for(int i = 0; i < 26; i++)
        visited[i] = false;
    list<int> queue;
    visited[u] = true;
    queue.push_back(u);
    while(!queue.empty()){
        u = queue.front();
        cout <<(char)(u+'a');
        mark[u] = true;
        queue.pop_front();
        for (auto c:graph[u]){
            if (visited[c] == false){
                visited[c] = true;
                queue.push_back(c);
            }
        }
    }
}
int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.size();
        degree.assign(27,0);
        mark.assign(27,false);
        bool flag= false;
        for(int i = 0;i<26;i++)graph[i].clear();
        for(int i = 0;i<n-1;i++){
            if(!add_edge(s[i]-'a',s[i+1]-'a')){cout<<"NO"<<endl;flag = true;break;}
        }
        if(flag)continue;
        if(n == 1){
            mark[s[0]-'a']= true;
            cout<<s[0];
            for(int i = 0;i<26;i++)if(!mark[i])cout<<(char)(i+'a');
            cout<<endl;
            continue;
        }
        int count1= 0,start= 0;
        for(int i = 0;i<26;i++)if(degree[i]== 1){count1++;start = i;};
        if(count1 != 2)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            bfs(start);
            for(int i = 0;i<26;i++)if(!mark[i])cout<<(char)(i+'a');
            cout<<endl;
        }

    }
    return 0;
}