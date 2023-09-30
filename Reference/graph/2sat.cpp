/**
 * Author:Alberto Silva
 * Date: 2022
 * License: CC0
 * Source: folklore
 * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, 
 * Here is an example of such a 2-SAT problem. Find an assignment of a,b,c such that the following formula is true:
 * so that an expression of the type $(a \vee \neg b) \wedge (\neg a \vee b) \wedge (\neg a \vee \neg b) \wedge ...$ becomes true, or reports that it is unsatisfiable.
 * Negated variables are represented by bit-inversions (\texttt{\~{}x}).
 * Status: stress-tested
 */


int N,timeD ;
vector<vector<int> > gr(1007);
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
// For must be same mask = 9 -> 1001
// for must be diferent mask = 6 -> 0110 ./
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
  for(int i = 0;i<N;i++) if (comp[2*i] == comp[2*i+1]) return 0;
  return 1;
}

