#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;
const int MAXN = 64 ;

char edges[MAXN][MAXN] ;
char nodes[MAXN][MAXN] ;
char adj[MAXN][MAXN] ;
char inp[MAXN][MAXN] ;
int n; 
vector<pair<int, int>> seq ;
ll cnt, checks ;
void display() {
   cnt++ ;
   for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++)
         if (edges[i][j])
            cout << '\\' ;
         else
            cout << '/' ;
      cout << endl ;
   }
   exit(0) ;
}
int dfs(int i, int j) {
   if (nodes[i][j])
      return nodes[i][j] ;
   nodes[i][j] = 1 ;
   int r = 1 ;
   if (i > 0 && j > 0 && edges[i-1][j-1])
      r = max(r, dfs(i-1, j-1)) ;
   if (i < n && j < n && edges[i][j])
      r = max(r, dfs(i+1, j+1)) ;
   if (i > 0 && j < n && !edges[i-1][j])
      r = max(r, dfs(i-1, j+1)) ;
   if (i < n && j > 0 && !edges[i][j-1])
      r = max(r, dfs(i+1, j-1)) ;
   nodes[i][j] = r ;
   return r ;
}
int check() {
   checks++ ;
   for (int i=1; i<n; i++)
      for (int j=1; j<n; j++)
         nodes[i][j] = 0 ;
   for (int i=0; i<=n; i++)
      nodes[0][i] = nodes[i][0] = nodes[n][i] = nodes[i][n] = 2 ;
   for (int i=1; i<n; i++)
      for (int j=1; j<n; j++)
         if (nodes[i][j] == 0)
            if (dfs(i,j) != 2)
               return 0 ;
   return 1 ;
}
void recur(int at) {
   if (at == (int)seq.size()) {
      if (check())
         display() ;
   } else {
      int i = seq[at].first ;
      int j = seq[at].second ;
      for (int v=0; v<2; v++) {
         /* no diamonds */
         if (v == 0 && i > 0 && j > 0 && edges[i-1][j-1] == 0 &&
             edges[i][j-1] == 1 && edges[i-1][j] == 1)
            continue ;
         edges[i][j] = v ;
         adj[i][j] += v ;
         adj[i][j+1] += 1-v ;
         adj[i+1][j] += 1-v ;
         adj[i+1][j+1] += v ;
         if ((inp[i][j] == '+' || inp[i][j] == adj[i][j]) &&
             (inp[i][j+1] == '+' ||
      (j+1 == n ? inp[i][j+1] == adj[i][j+1] : inp[i][j+1] >= adj[i][j+1])) &&
             (inp[i+1][j] == '+' ||
    (i + 1 == n ? inp[i+1][j] == adj[i+1][j] : inp[i+1][j] >= adj[i+1][j])) &&
             (inp[i+1][j+1] == '+' ||
 ((i + 1 == n && j + 1 == n) ? inp[i+1][j+1] == adj[i+1][j+1] : inp[i+1][j+1] >= adj[i+1][j+1])))
            recur(at+1) ;
         adj[i][j] -= v ;
         adj[i][j+1] -= 1-v ;
         adj[i+1][j] -= 1-v ;
         adj[i+1][j+1] -= v ;
      }
   }
}
int main() {
    cin >> n ;
    string s ;
    for (int i=0; i<=n; i++){
        cin>>s ;
        for (int j=0; j<=n; j++)
            inp[i][j] = (s[j] == '+' ? '+' : s[j]-'0') ;
    }
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            seq.push_back({i,j}) ;
    recur(0) ;
    if (cnt != 1)
        cout << "Found " << cnt << " solutions." << endl ;
}