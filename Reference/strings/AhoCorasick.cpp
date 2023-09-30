/**
 * Author: Alberto SIlva
 * Description: Aho-Corasick automaton, used for multiple pattern matching.
 * Initialize with AhoCorasick ac(patterns); the automaton start node will be at index 0.
 * find(word) returns for each position the index of the longest word that ends there, or -1 if none.
 * findAll($-$, word) finds all words (up to $N \sqrt N$ many if no duplicate patterns)
 * that start at each position (shortest first).
 * Duplicate patterns are allowed; empty patterns are not.
 * To find the longest words that start at each position, reverse all input.
 * Considerations:
 * 		The exit links are a compression of links , with exit links go directly to 
 * 		the next node that is a end of some word
 * Time: construction takes $O(kN)$, where $N =$ sum of length of patterns and K is the size of alphabet. 
 * find(x) is $O(N)$, where N = length of x. findAll is $O(NM)$.
 * Status: stress-tested
* Usage:         AHO.insert($s_i$) //for all $s_i$;AHO.pushLinks();
 */

struct AhoCorasick {
    struct Node : map<char, int> {
        int link = 0;
        int cnt = 0;
        int tin = 0, tout = 0;
    };
    
    vector<Node> trie;
    vector<vi> graph;
    
    AhoCorasick() { newNode(); }
    
    int newNode() {
        trie.pb({});
        graph.pb({});
        return sz(trie) - 1;
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
        queue<int> Q;
        Q.push(0);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto &[c, v] : trie[u]) {
                int l = (trie[v].link = u ? go(trie[u].link, c) : 0);
                trie[v].cnt += trie[l].cnt; 
                Q.push(v);
            }
        }
    }
    
    void buildTree() {
        fore (u, 0, sz(trie))
            graph[trie[u].link].pb(u);
  
        int timer = 0;  
        function<void(int)> dfs = [&](int u) {
            trie[u].tin = ++timer;
            for (int v : graph[u])
                if (!trie[v].tin)
                dfs(v);
            trie[u].tout = timer;
        };    
    
        dfs(0);
    }
    
    int match(string &s, int u = 0) {
        lli ans = 0;
        for (char c : s) {
            u = go(u, c);
            ans += trie[u].cnt;
        }
        return ans;
    }
    Node& operator [](int u) {
        return trie[u];
    }
}AHO;