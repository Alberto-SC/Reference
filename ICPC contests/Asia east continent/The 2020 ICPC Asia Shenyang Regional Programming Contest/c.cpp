#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int N,timeD = 0;
vector<vector<int> > gr(2e6+7);
vector<int> val, comp, z; 
vector<int> values; // 0 = false, 1 = true
void addCondition(int u, int v,int Nu,int Nv) {
  (u*=2)^=Nu;
  (v*=2)^=Nv;
  gr[u^1].push_back(v);
  gr[v^1].push_back(u);

}

// 0 -> 00
// 1 -> 01 
// 2 -> 10
// 3 -> 11 
void canBe(int u,int v,int mask){
    if(!(mask&1)){  
        addCondition(u,v,1,1);
    }
    if(!((mask>>1)&1)){
        addCondition(u,v,1,0);
    }
    if(!((mask>>2)&1)){
        addCondition(u,v,0,1);
    }
    if(!((mask>>3)&1)){
        addCondition(u,v,0,0);
    }
}

void cannotBe(int u,int v,int mask){
    if((mask&1)){  
        addCondition(u,v,0,0);
    }
    if(((mask>>1)&1)){
        addCondition(u,v,0,1);
    }
    if(((mask>>2)&1)){
        addCondition(u,v,1,0);
    }
    if(((mask>>3)&1)){
        addCondition(u,v,1,1);
    }
}



int dfs(int i) {
  int low = val[i] = ++timeD, x; z.push_back(i);
  for(int j = 0;j<gr[i].size();j++){
    int e = gr[i][j];
    if (!comp[e])
      low = min(low, val[e] ?: dfs(e));
  } 
  ++timeD;
  if (low == val[i]) do {
    x = z.back(); z.pop_back();
    comp[x] = timeD;
    if (values[x>>1] == -1)
      values[x>>1] = !(x&1);
  } while (x != i);

  return val[i] = low;
}

bool solve() {
  values.assign(N, -1);
  val.assign(2*N, 0); comp = val;
  timeD = 0;
  for(int i = 0;i<2*N;i++) 
          if(!comp[i]) 
              dfs(i);
  for(int i = 0;i<N;i++) if (comp[2*i] == comp[(2*i)+1]) return 0;
  return 1;
}



signed main(){
    int T = 1,n,m;
    cin>>m>>n;
    N = n;
    string s;
    getline(cin, s);
    set<string> mp[n]; 
    vector<bool> conflict(n);
    for(int i = 0;i<m;i++){
        getline(cin, s);
        istringstream in(s);
        vector<string> words;
        string w;
        while(getline(in, w, ' ')){
            words.push_back(w);
        }
        int idx = 0;
        vector<string> V[2];
        for(auto c:words){
            if(c== "->"){
                idx++;
                continue;
            }
            V[idx].push_back(c);
        }
        int u,v;
        if(idx == 0){
            if(V[0][0][0]== '!'){
                u = stoll(V[0][0].substr(1)); 
                u--;
                addCondition(u,u,1,1);
            }
            else{
                u = stoll(V[0][0]);
                u--;
                addCondition(u,u,0,0);
            }
        }
        else{
            bool neg = false;
            if(V[1][0][0]=='!'){
                neg = true;
                v = stoll(V[1][0].substr(1));
            }
            else 
                v = stoll(V[1][0]);

            v--;
            for(auto c:V[0]){
                u = stoll(c);
                u--;
                if(neg){
                    if(mp[u].count("+"+to_string(v))){
                        conflict[u] = true;
                        addCondition(u,u,1,1);
                    }
                    mp[u].insert("-"+to_string(v));
                    // cout<<u<<" !"<<v<<endl;
                    cannotBe(u,v,8);
                }
                else{
                    if(mp[u].count("-"+to_string(v))){
                        conflict[u] = true;
                        addCondition(u,u,1,1);
                    }
                    mp[u].insert("+"+to_string(v));
                    // cout<<u<<" "<<v<<endl;
                    cannotBe(u,v,4);
                }
            }
        }
    }

    if(solve()){
        string ans = "";
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(values[i]){
                ans+="T";
            }
            else ans+="F";
        }
        cout<<ans<<endl;
    }   
    else{
        cout<<"conflict"<<endl;
    }
    return 0;
}