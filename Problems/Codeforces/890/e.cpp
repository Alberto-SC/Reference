#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxn = 1000007;
vector<int> graph[maxn];
 
int closest;
template <int len = 1>
void subset_sum(int n,vector<pair<int,int>> &b) {
    if (n >= len) {
        subset_sum<std::min(len*2, maxn)>(n,b);
        return;
    }
    
    bitset<len> dp;
    dp[0] = 1;
    for(int i = 0;i<b.size();i++){
        int m = b[i].second;
        int val = b[i].first;
        for(int x = 0;(1<<x)<=m;x++){
            dp|= (dp<<((1<<x)*val));
            m-=1<<x;
        } 
        dp |= (dp<<(m*val));
    }
 
    closest = 0;
    for (int i = n/2; i >=0; i--) {
        if(dp[i]){
            closest = i;
            break;
        }
    }
}
 
int solve(vector<int> &a) {
    sort(a.begin(),a.end());
    if (a.back() * 2 >= accumulate(a.begin(), a.end(), 0LL))
        return a.back();
    
    a.push_back(0);
    vector<pair<int,int>> b;
    int last = 0;
    for (int i = 1; i <a.size(); i++) {
        if (a[i] != a[i - 1]) {
            int cnt = i-last;
            b.push_back({a[i - 1], cnt});
            last=i;
        }
    }
 
    subset_sum(accumulate(a.begin(), a.end(), 0LL),b);
    return closest;
}

int ans = 0;
vector<int> sz(maxn);
void dfs(int u,int p = -1){
  sz[u] = 1;
  for(auto v:graph[u]){
    if(v == p)continue;
    dfs(v,u);
    sz[u]+=sz[v];
  }

  vector<int> V;
  int total = 0;
  for(auto v:graph[u]){
    if(v == p)continue;
    V.push_back(sz[v]);    
    total+=sz[v];
  }

  if(V.size()==0)return;
  int x = solve(V); 
  ans+=x*(total-x);

}



signed main(){__
  int T = 1,n;
  cin>>n;

  for(int i = 0;i<n-1;i++){
    int p;
    cin>>p;
    graph[i+1].push_back(p-1);
    graph[p-1].push_back(i+1);
  }

  dfs(0);
  cout<<ans<<endl;
  return 0;
}