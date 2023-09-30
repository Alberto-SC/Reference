#include <bits/stdc++.h>
/**
 * Description: A self balanced tree that allows mantain a full dinamyc array
 and get information in ranges
 * Time: $O(log n)$ per query, $O(N \log N)$ build
 * Status: stress-tested
 */

namespace allocator {

// Array allocator.
template <class T, int MAXSIZE>
struct array {
  T v[MAXSIZE], *top;
  array() : top(v) {}
  T *alloc(const T &val = T()) { return &(*top++ = val); }
  void dealloc(T *p) {}
};

// Stack-based array allocator.
template <class T, int MAXSIZE>
struct stack {
  T v[MAXSIZE];
  T *spot[MAXSIZE], **top;
  stack() {
    for (int i = 0; i < MAXSIZE; ++i) spot[i] = v + i;
    top = spot + MAXSIZE;
  }
  T *alloc(const T &val = T()) { return &(**--top = val); }
  void dealloc(T *p) { *top++ = p; }
};

}  // namespace allocator

namespace splay {

// Abstract node struct.
template <class T>
struct node {
  T *f, *c[2];
  int size;
  node() {
    f = c[0] = c[1] = nullptr;
    size = 1;
  }
  void push_down() {}
  void update() {
    size = 1;
    for (int t = 0; t < 2; ++t)
      if (c[t]) size += c[t]->size;
  }
};

// Abstract reversible node struct.
template <class T>
struct reversible_node : node<T> {
  int r;
  reversible_node() : node<T>() { r = 0; }
  void push_down() {
    node<T>::push_down();
    if (r) {
      for (int t = 0; t < 2; ++t)
        if (node<T>::c[t]) node<T>::c[t]->reverse();
      r = 0;
    }
  }
  void update() { node<T>::update(); }
  // Reverse the range of this node.
  void reverse() {
    std::swap(node<T>::c[0], node<T>::c[1]);
    r = r ^ 1;
  }
};

template <class T, int MAXSIZE = 500000,
          class alloc = allocator::array<T, MAXSIZE + 2>>
struct tree {
  alloc pool;
  T *root;
  // Get a new node from the pool.
  T *new_node(const T &val = T()) { return pool.alloc(val); }
  tree() {
    root = new_node(), root->c[1] = new_node(), root->size = 2;
    root->c[1]->f = root;
  }
  // Helper function to rotate node.
  void rotate(T *n) {
    int v = n->f->c[0] == n;
    T *p = n->f, *m = n->c[v];
    if (p->f) p->f->c[p->f->c[1] == p] = n;
    n->f = p->f, n->c[v] = p;
    p->f = n, p->c[v ^ 1] = m;
    if (m) m->f = p;
    p->update(), n->update();
  }
  // Splay n so that it is under s (or to root if s is null).
  void splay(T *n, T *s = nullptr) {
    while (n->f != s) {
      T *m = n->f, *l = m->f;
      if (l == s)
        rotate(n);
      else if ((l->c[0] == m) == (m->c[0] == n))
        rotate(m), rotate(n);
      else
        rotate(n), rotate(n);
    }
    if (!s) root = n;
  }
  // Get the size of the tree.
  int size() { return root->size - 2; }
  // Helper function to walk down the tree.
  int walk(T *n, int &v, int &pos) {
    n->push_down();
    int s = n->c[0] ? n->c[0]->size : 0;
    (v = s < pos) && (pos -= s + 1);
    return s;
  }
  // Insert node n to position pos.
  void insert(T *n, int pos) {
    T *c = root;
    int v;
    ++pos;
    while (walk(c, v, pos), c->c[v] && (c = c->c[v]))
      ;
    c->c[v] = n, n->f = c, splay(n);
  }
  // Find the node at position pos. If sp is true, splay it.
  T *find(int pos, int sp = true) {
    T *c = root;
    int v;
    ++pos;
    while ((pos < walk(c, v, pos) || v) && (c = c->c[v]))
      ;
    if (sp) splay(c);
    return c;
  }
  // Find the range [posl, posr) on the splay tree.
  T *find_range(int posl, int posr) {
    T *r = find(posr), *l = find(posl - 1, false);
    splay(l, r);
    if (l->c[1]) l->c[1]->push_down();
    return l->c[1];
  }
  // Insert nn of size nn_size to position pos.
  void insert_range(T **nn, int nn_size, int pos) {
    T *r = find(pos), *l = find(pos - 1, false), *c = l;
    splay(l, r);
    for (int i = 0; i < nn_size; ++i) c->c[1] = nn[i], nn[i]->f = c, c = nn[i];
    for (int i = nn_size - 1; i >= 0; --i) nn[i]->update();
    l->update(), r->update(), splay(nn[nn_size - 1]);
  }
  // Helper function to dealloc a subtree.
  void dealloc(T *n) {
    if (!n) return;
    dealloc(n->c[0]);
    dealloc(n->c[1]);
    pool.dealloc(n);
  }
  // Remove from position [posl, posr).
  void erase_range(int posl, int posr) {
    T *n = find_range(posl, posr);
    n->f->c[1] = nullptr, n->f->update(), n->f->f->update(), n->f = nullptr;
    dealloc(n);
  }
};

}  // namespace splay


const int MAXSIZE = 200000;

struct node: splay::reversible_node<node> {
  long long val, val_min, label_add;
  node(long long v = 0) : splay::reversible_node<node>(), val(v) { val_min = label_add = 0; }
  // Add v to the subtree.
  void add(long long v) {
    val += v;
    val_min += v;
    label_add += v;
  }
  void push_down() {
    splay::reversible_node<node>::push_down();
    for (int t = 0; t < 2; ++t) if (c[t]) c[t]->add(label_add);
    label_add = 0;
  } 
  void update() {
    splay::reversible_node<node>::update();
    val_min = val;
    for (int t = 0; t < 2; ++t) if (c[t]) val_min = std::min(val_min, c[t]->val_min);
  }
};

splay::tree<node, MAXSIZE, allocator::stack<node, MAXSIZE + 2>> t;

int main() {
  int N, M;
  scanf("%d", &N);
  while (N--) {
    long long u; scanf("%lld", &u);
    t.insert(t.new_node(node(u)), t.size());
  }
  scanf("%d", &M);
  while (M--) {
    char c[10];
    scanf("%s", c);
    if (strcmp(c, "ADD") == 0) {
      int x, y; long long D;
      scanf("%d%d%lld", &x, &y, &D);
      t.find_range(x - 1, y)->add(D);
    } else if (strcmp(c, "REVERSE") == 0) {
      int x, y;
      scanf("%d%d", &x, &y);
      t.find_range(x - 1, y)->reverse();
    } else if (strcmp(c, "REVOLVE") == 0) {
      int x, y; long long T;
      scanf("%d%d%lld", &x, &y, &T);
      T %= (y - x + 1);
      if (T > 0) {
        // swap [x - 1, y - T) and [y - T, y)
        node *right = t.find_range(y - T, y);
        right->f->c[1] = nullptr, right->f->update(), right->f->f->update(), right->f = nullptr;
        t.insert(right, x - 1);
      }
    } else if (strcmp(c, "INSERT") == 0) {
      int x; long long P;
      scanf("%d%lld", &x, &P);
      t.insert(t.new_node(node(P)), x);
    } else if (strcmp(c, "DELETE") == 0) {
      int x;
      scanf("%d", &x);
      t.erase_range(x - 1, x);
    } else if (strcmp(c, "MIN") == 0) {
      int x, y;
      scanf("%d%d", &x, &y);
      printf("%lld\n", t.find_range(x - 1, y)->val_min);
    }
  }
}