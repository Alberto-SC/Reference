#include <bits/stdc++.h>
using namespace std;

const int maxn = 1007;
vector<int> graph[maxn];

bool flag = false;
int start;
void dfs(int u,set<int> st,vector<int> current,set<int> Crr){
  set<int> nw;
  for(auto c:graph[u])
    nw.insert(c);
  for(auto c:st)
    nw.insert(c);


  current.push_back(u);    
  Crr.insert(u);
  for(auto v:graph[u]){
    if(v == start){
      int cont = 0;
      for(auto c:current){
        for(auto e:graph[c]){
          if(Crr.count(e))cont++;
        }
      }
      if(cont!=current.size())continue;
      cout<<current.size()<<endl;
      flag = true;
      for(auto c:current){
        cout<<c+1<<endl;
      }
      exit(0);
      return ;
    }
    else if(!st.count(v) && !Crr.count(v)){
      nw.erase(v);
      dfs(v,nw,current,Crr);
      nw.insert(v);
    }
  }
}


int main(){
  int n,m,u,v;
  cin>>n>>m;
  for(int i = 0;i<m;i++){
    cin>>u>>v;
    u--,v--;
    graph[u].push_back(v);
  }

  for(int i = 0;i<n;i++){
    start = i;
    dfs(i,{},{},{});
    if(flag)break;
  }
  if(!flag)cout<<-1<<endl;
  return 0;
}
