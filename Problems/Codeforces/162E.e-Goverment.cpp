#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios__base::sync_with_stdio(false),cin.tie(NULL);

using lli = long long;
using vi = vector<int>;

const int N = 1e5 + 5;

bitset<N> vis;
int pos[N];
string s;
int n, k;

template <class T>
struct Fenwick {
  #define lsb(x) (x & -x)
  vector<T> fenw;

  Fenwick(int n = 1) : fenw(n + 1, {}) {}

  void update(int i, T v) {
    for (; i < fenw.size(); i += lsb(i))
      fenw[i] += v;
  }

  void update(int l, int r, T v) {
    update(l, v);
    update(r + 1, -v);
  }

  T query(int i) {
    T v = {};
    for (; i > 0; i -= lsb(i))
      v += fenw[i];
    return v;
  }

  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

struct AhoCorasick {
  struct Node : map<char, int> {
    int link = 0;
    lli cnt = 0;
    int tin = 0, tout = 0;
  };
  
  vector<Node> trie;
  vector<vi> graph;
  Fenwick<lli> government;

  AhoCorasick() { newNode(); }

  int newNode() {
    trie.push_back({});
    graph.push_back({});
    return trie.size() - 1;
  }

  int insert(string &s, int u = 0) {
    for (char c : s) {
      if (!trie[u][c])
        trie[u][c] = newNode();
      u = trie[u][c];
    }
    trie[u].cnt++;
    return u;
  }

  int go(int u, char c) {
    while (u && !trie[u].count(c))
      u = trie[u].link;
    return trie[u][c];
  }

  void pushLinks() {
    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
      int u = qu.front();
      qu.pop();
      for (auto &[c, v] : trie[u]) {
        int l = (trie[v].link = u ? go(trie[u].link, c) : 0);
        trie[v].cnt += trie[l].cnt;
        qu.push(v);
      }
    }
  }

  void buildTree() {
    for (int u=0 ;u<trie.size();u++)
      graph[trie[u].link].push_back(u);
    int timer = 0;

    function<void(int)> dfs = [&](int u) {
      trie[u].tin = ++timer;
      for (int v : graph[u])
        if (!trie[v].tin)
          dfs(v);
      trie[u].tout = timer;
    };    

    dfs(0);

    government = Fenwick<lli>(trie.size() + 10);
  }

  lli match(string &s, int u = 0) {
    lli ans = 0;
    for (char c : s) {
      u = go(u, c);
      ans += trie[u].cnt;
      ans += government.query(trie[u].tin);
    }
    return ans;
  }

  Node& operator [](int u) {
    return trie[u];
  }
} aho;

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  auto begin = clock();
  cin >> n >> k;
  for (int id = 1;id< k + 1;id++) {
    cin >> s;
    pos[id] = aho.insert(s);
    vis[id] = 1;
  }
  aho.pushLinks();
  aho.buildTree();
  for (int i = 0;i<n;i++) {
    cin >> s;

    char op = s[0];  
    s = s.substr(1);  

    if (op == '?') {
      // cout << aho.match(s) << '\n';
    } else {
      int id = stoi(s);
      int u = pos[id];
      if (op == '+' && !vis[id]) {
        aho.government.update(aho[u].tin, aho[u].tout, +1);
        vis[id] = 1;
      } else if (op == '-' && vis[id]) {
        aho.government.update(aho[u].tin, aho[u].tout, -1);
        vis[id] = 0;
      }
    }
  }
  auto end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // cout<<aho.trie.size()<<endl;
  cout<<fixed<<setprecision(6)<<time_spent<<endl;
  
  return 0;
}   