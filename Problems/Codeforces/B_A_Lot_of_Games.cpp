#include <bits/stdc++.h>
using namespace std;
 
int nextInt() {
    int x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}
 
const int max_len = 100500, max_alpha = 26;
 
int t[max_len][max_alpha];
int szT;
 
int newT() {
    return ++szT;
}
 
int n, k, root;
char s[max_len];
bool win[max_len], lose[max_len];
 
void addTrie(char * s) {
    int len = strlen(s);
    int v = root;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (t[v][c] == 0) t[v][c] = newT();
        v = t[v][c];
    }
}
 
void dfs(int v) {
    win[v] = false;
    lose[v] = false;
    bool isLeaf = true; //
    for (int i = 0; i < max_alpha; i++) {
        if (t[v][i] != 0) {
            isLeaf = false;
            int to = t[v][i];
            dfs(to);
            win[v] |= !win[to];
            lose[v] |= !lose[to];
        }
    }
    if (isLeaf) {
        lose[v] = true;
    }
}
 
void answer(bool res) {
    puts(res ? "First" : "Second");
    exit(0);
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    n = nextInt();
    k = nextInt();
    root = newT();
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        addTrie(s);
    }
    dfs(root);
    if (k == 1) answer(win[root]); //1 game
    else if (!win[root]) answer(win[root]); //answer(0);
    else if (lose[root]) answer(win[root]); //answer(1);
    else if (k % 2 == 1) answer(win[root]); //answer(1)
    else answer(!win[root]); //answer(0)
}