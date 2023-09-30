#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int M[1007][1007];
int sum[1007][1007];
int MX[1007][1007];

int n,m;
void prefixSums(){
  sum[0][0] = M[0][0];

  for(int i = 0;i<n;i++)
    sum[i][0] = sum[i-1][0]+ M[i][0]; 
  
  for(int i = 0;i<m;i++)
    sum[0][i] = sum[0][i-1]+M[0][i];

  for(int i = 1;i<n;i++){
    for(int j = 0;j<m;j++){
      sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+ M[i][j];
    }
  }
}

int sum2D(int x0,int y0,int x1,int y1){
  int u = 0;
  int d = 0;
  int l = 0;

  if(x0 && y0)d = sum[x0-1][y0-1];
  if(y0) l = sum[x1][y0-1];
  if(x0) u = sum[x0-1][y1];

  return sum[x1][y1]-l-u+d;
}

int max2D(int a,int b){

  vector<int> columns[n];

  for(int i = 0;i<n;i++){
    deque<int> d;

    for(int j = 0;j<b;j++){
      while(d.size() && M[i][d.back()]<M[i][j])
        d.pop_back();
      d.push_back(j);
    }

    columns[i].push_back(d.front());
  
    for(int j = b;j<m;j++){
      if(d.front()<=j-b)
        d.pop_front();

      while(d.size() &&M[i][d.back()]<M[i][j])
        d.pop_back();
      d.push_back(j);
      columns[i].push_back(d.front());
    }
  }

  for(int i = 0;i<n;i++){
    for(auto &c:columns[i])c = M[i][c];
  }
  int mx = 0;

  for(int i = 0;i<=m-b;i++){
    deque<int> d;
    for(int j = 0;j<a;j++){
      while(d.size() && columns[d.back()][i] < columns[j][i])
        d.pop_back();
      d.push_back(j);
    }
    MX[0][i] = columns[d.front()][i]; 
    for(int j = a;j<n;j++){
      if(d.front()<=j-a)
        d.pop_front();
      
      while(d.size() && columns[d.back()][i]<columns[j][i])
        d.pop_back();
      d.push_back(j);
      MX[(j-a)+1][i] = columns[d.front()][i];
      mx = max(mx,d.front());
    }
  }
  return mx;
}

signed main(){__
  int q,a,b;
  cin>>n>>m;
  for(int i = 0;i<n;i++){
    for(int j= 0;j<m;j++){
      cin>>M[i][j];
    }
  }
  prefixSums();
  
  cin>>q;

  while(q--){
    cin>>a>>b;
    max2D(a,b);
    int ans = 1e9;
    for(int i = 0;i<=n-a;i++){
        for(int j = 0;j<=m-b;j++){
          int mx = MX[i][j];
          int target = a*b*mx;
          int need = target-sum2D(i,j,(i+a)-1,(j+b)-1);
          ans = min(need,ans);      
        } 
    }
    cout<<ans<<endl;
      
  }
  return 0;
}
