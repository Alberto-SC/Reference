#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100010
struct qnode
{
    int tp, x, y, id; bool isleft;
    qnode () {}
    qnode (int tp, int x, int y, int id) : tp(tp), x(x), y(y), id(id) {}
    bool operator < (const qnode &other) const { return x < other.x || x == other.x && id < other.id; }
}que[N << 2], tque[N << 2];
int n, m, q, brr[N << 2];
ll ans[N];

void Hash()
{
    sort(brr + 1, brr + 1 + m);
    m = unique(brr + 1, brr + 1 + m) - brr - 1;
    for (int i = 1; i <= n; ++i) que[i].y = lower_bound(brr + 1, brr + 1 + m, que[i].y) - brr;
}

namespace BIT
{
    int a[N << 2];
    void init() { memset(a, 0, sizeof a); }
    void update(int x, int val)
    {
        for (; x <= m; x += x & -x)
        {
            if (val == 0) a[x] = 0;
            else a[x] += val;
        }
    }
    ll query(int x)
    {
        ll res = 0;
        for (; x; x -= x & -x)
            res += a[x];
        return res;
    }
}

void CDQ1(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    for (int i = l; i <= r; ++i)
    {
        tque[i] = que[i];
        if (i <= mid) tque[i].isleft = true;
        else tque[i].isleft = false;
    }
    sort(tque + l, tque + 1 + r);
    for (int i = l; i <= r; ++i)
    {
        if (tque[i].tp == 0 && tque[i].isleft == true) BIT::update(tque[i].y, 1);
        else if (tque[i].tp && tque[i].isleft == false)ans[tque[i].id] += BIT::query(tque[i].y) * tque[i].tp;
    }
    for (int i = l; i <= r; ++i) if (tque[i].tp == 0 && tque[i].isleft == true) BIT::update(tque[i].y, 0);
    CDQ1(l, mid), CDQ1(mid + 1, r);
}

void CDQ2(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    for (int i = l; i <= r; ++i)
    {
        tque[i] = que[i];
        if (i <= mid) tque[i].isleft = true;
        else tque[i].isleft = false;
    }
    sort(tque + l, tque + 1 + r, [](qnode a, qnode b) { return a.x > b.x || a.x == b.x && a.id < b.id; });
    for (int i = l; i <= r; ++i)
    {
        if (tque[i].tp != 0 && tque[i].isleft == true) BIT::update(tque[i].y, tque[i].tp);
        else if (tque[i].tp == 0 && tque[i].isleft == false) ans[tque[i].id] += BIT::query(m) - BIT::query(tque[i].y - 1);
    }
    for (int i = l; i <= r; ++i) if (tque[i].tp && tque[i].isleft == true) BIT::update(tque[i].y, 0);
    CDQ2(l, mid); CDQ2(mid + 1, r);
}

int main()
{
    while (scanf("%d", &q) != EOF)
    {
        n = 0; ans[0] = 0; m = 0;
        memset(ans, 0, sizeof ans);
        for (int i = 1, op, x[2], y[2]; i <= q; ++i)
        {
            scanf("%d%d%d", &op, x, y);
            brr[++m] = y[0]; brr[++m] = y[0] - 1;
            if (op == 1) que[++n] = qnode(0, x[0], y[0], i);
            else
            {
                scanf("%d%d", x + 1, y + 1);
                brr[++m] = y[1]; brr[++m] = y[1] - 1;
                que[++n] = qnode(1, x[0] - 1, y[0] - 1, i);
                que[++n] = qnode(1, x[1], y[1], i);
                que[++n] = qnode(-1, x[0] - 1, y[1], i);
                que[++n] = qnode(-1, x[1], y[0] - 1, i);
            }
        }
        Hash(); BIT::init();
        CDQ1(1, n); CDQ2(1, n);
        for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i] += ans[i - 1]);
    }
    return 0;
}