#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct JiDriverSegmentTree {
    static const int T = (1 << 19);
    static const long long INF = 1e15 + 7;

    struct Node {
        long long min;
        int minCnt;
        long long secondMin;

        long long max;
        int maxCnt;
        long long secondMax;

        long long sum;
        long long diffGcd;

        long long pushSum;
        long long pushEq;
        // If we have pushEq, no other pushes should be made. They're all combined together in pushEq.
        // Otherwise we first apply pushSum and then min= and max= pushes (in any order btw).
    } tree[T];

    int n;

    void doPushEq(int v, int l, int r, long long val) {
        tree[v].min = tree[v].max = tree[v].pushEq = val;
        tree[v].minCnt = tree[v].maxCnt = r - l;
        tree[v].secondMax = -INF;
        tree[v].secondMin = INF;

        tree[v].sum = val * (r - l);
        tree[v].diffGcd = 0;
        tree[v].pushSum = 0;
    }

    void doPushMinEq(int v, int l, int r, long long val) {
        if (tree[v].min >= val) {
            doPushEq(v, l, r, val);
        } else if (tree[v].max > val) {
            if (tree[v].secondMin == tree[v].max) {
                tree[v].secondMin = val;
            }
            tree[v].sum -= (tree[v].max - val) * tree[v].maxCnt;
            tree[v].max = val;
        }
    }

    void doPushMaxEq(int v, int l, int r, long long val) {
        if (tree[v].max <= val) {
            doPushEq(v, l, r, val);
        } else if (tree[v].min < val) {
            if (tree[v].secondMax == tree[v].min) {
                tree[v].secondMax = val;
            }
            tree[v].sum += (val - tree[v].min) * tree[v].minCnt;
            tree[v].min = val;
        }
    }

    void doPushSum(int v, int l, int r, long long val) {
        if (tree[v].min == tree[v].max) {
            doPushEq(v, l, r, tree[v].min + val);
        } else {
            tree[v].max += val;
            if (tree[v].secondMax != -INF) {
                tree[v].secondMax += val;
            }

            tree[v].min += val;
            if (tree[v].secondMin != INF) {
                tree[v].secondMin += val;
            }

            tree[v].sum += (r - l) * val;
            tree[v].pushSum += val;
        }
    }

    void pushToChildren(int v, int l, int r) {
        if (l + 1 == r) {
            return;
        }
        int mid = (r + l) / 2;
        if (tree[v].pushEq != -1) {
            doPushEq(2 * v, l, mid, tree[v].pushEq);
            doPushEq(2 * v + 1, mid, r, tree[v].pushEq);
            tree[v].pushEq = -1;
        } else {
            doPushSum(2 * v, l, mid, tree[v].pushSum);
            doPushSum(2 * v + 1, mid, r, tree[v].pushSum);
            tree[v].pushSum = 0;

            doPushMinEq(2 * v, l, mid, tree[v].max);
            doPushMinEq(2 * v + 1, mid, r, tree[v].max);

            doPushMaxEq(2 * v, l, mid, tree[v].min);
            doPushMaxEq(2 * v + 1, mid, r, tree[v].min);
        }
    }

    void updateFromChildren(int v) {
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;

        tree[v].max = max(tree[2 * v].max, tree[2 * v + 1].max);
        tree[v].secondMax = max(tree[2 * v].secondMax, tree[2 * v + 1].secondMax);
        tree[v].maxCnt = 0;
        if (tree[2 * v].max == tree[v].max) {
            tree[v].maxCnt += tree[2 * v].maxCnt;
        } else {
            tree[v].secondMax = max(tree[v].secondMax, tree[2 * v].max);
        }
        if (tree[2 * v + 1].max == tree[v].max) {
            tree[v].maxCnt += tree[2 * v + 1].maxCnt;
        } else {
            tree[v].secondMax = max(tree[v].secondMax, tree[2 * v + 1].max);
        }

        tree[v].min = min(tree[2 * v].min, tree[2 * v + 1].min);
        tree[v].secondMin = min(tree[2 * v].secondMin, tree[2 * v + 1].secondMin);
        tree[v].minCnt = 0;
        if (tree[2 * v].min == tree[v].min) {
            tree[v].minCnt += tree[2 * v].minCnt;
        } else {
            tree[v].secondMin = min(tree[v].secondMin, tree[2 * v].min);
        }
        if (tree[2 * v + 1].min == tree[v].min) {
            tree[v].minCnt += tree[2 * v + 1].minCnt;
        } else {
            tree[v].secondMin = min(tree[v].secondMin, tree[2 * v + 1].min);
        }

        tree[v].diffGcd = gcd(tree[2 * v].diffGcd, tree[2 * v + 1].diffGcd);

        long long anyLeft = tree[2 * v].secondMax; // any value that's not equal to left child max and min
        long long anyRight = tree[2 * v + 1].secondMax; // any value that's not equal to right child max and min
        if (anyLeft != -INF && anyLeft != tree[2 * v].min && anyRight != -INF && anyRight != tree[2 * v + 1].min) {
            tree[v].diffGcd = gcd(tree[v].diffGcd, anyLeft - anyRight); // connect two spanning trees
        }

        long long any = -1; // any value that's not equal to current vertex max and min
        if (anyLeft != -INF && anyLeft != tree[2 * v].min) {
            any = anyLeft;
        } else if (anyRight != -INF && anyRight != tree[2 * v + 1].min) {
            any = anyRight;
        }

        // adding all values that are not max and min anymore to diffGcd
        for (long long val : {tree[2 * v].min, tree[2 * v].max, tree[2 * v + 1].min, tree[2 * v + 1].max}) {
            if (val != tree[v].min && val != tree[v].max) {
                if (any != -1) {
                    tree[v].diffGcd = gcd(tree[v].diffGcd, val - any);
                } else {
                    any = val;
                }
            }
        }
    }

    void build(int v, int l, int r, const vector<int>& inputArray) {
        tree[v].pushSum = 0;
        tree[v].pushEq = -1;
        if (l + 1 == r) {
            tree[v].max = inputArray[l];
            tree[v].secondMax = -INF;
            tree[v].maxCnt = 1;

            tree[v].min = inputArray[l];
            tree[v].secondMin = INF;
            tree[v].minCnt = 1;

            tree[v].diffGcd = 0;
            tree[v].sum = inputArray[l];
        } else {
            int mid = (r + l) / 2;
            build(2 * v, l, mid, inputArray);
            build(2 * v + 1, mid, r, inputArray);
            updateFromChildren(v);
        }
    }

    void build(const vector<int>& inputArray) {
        n = inputArray.size();
        build(1, 0, n, inputArray);
    }

    void updateMinEq(int v, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql || tree[v].max <= val) {
            return;
        }
        if (ql <= l && r <= qr && tree[v].secondMax < val) {
            doPushMinEq(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        updateMinEq(2 * v, l, mid, ql, qr, val);
        updateMinEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updateMinEq(int ql, int qr, int val) {
        updateMinEq(1, 0, n, ql, qr, val);
    }

    void updateMaxEq(int v, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql || tree[v].min >= val) {
            return;
        }
        if (ql <= l && r <= qr && tree[v].secondMin > val) {
            doPushMaxEq(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        updateMaxEq(2 * v, l, mid, ql, qr, val);
        updateMaxEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updateMaxEq(int ql, int qr, int val) {
        updateMaxEq(1, 0, n, ql, qr, val);
    }

    void updateEq(int v, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            doPushEq(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        updateEq(2 * v, l, mid, ql, qr, val);
        updateEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updateEq(int ql, int qr, int val) {
        updateEq(1, 0, n, ql, qr, val);
    }

    void updatePlusEq(int v, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            doPushSum(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        updatePlusEq(2 * v, l, mid, ql, qr, val);
        updatePlusEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updatePlusEq(int ql, int qr, int val) {
        updatePlusEq(1, 0, n, ql, qr, val);
    }

    long long findSum(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return tree[v].sum;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        return findSum(2 * v, l, mid, ql, qr) + findSum(2 * v + 1, mid, r, ql, qr);
    }

    long long findSum(int ql, int qr) {
        return findSum(1, 0, n, ql, qr);
    }

    long long findMin(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return INF;
        }
        if (ql <= l && r <= qr) {
            return tree[v].min;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        return min(findMin(2 * v, l, mid, ql, qr), findMin(2 * v + 1, mid, r, ql, qr));
    }

    long long findMin(int ql, int qr) {
        return findMin(1, 0, n, ql, qr);
    }

    long long findMax(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return -INF;
        }
        if (ql <= l && r <= qr) {
            return tree[v].max;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        return max(findMax(2 * v, l, mid, ql, qr), findMax(2 * v + 1, mid, r, ql, qr));
    }

    long long findMax(int ql, int qr) {
        return findMax(1, 0, n, ql, qr);
    }

    long long findGcd(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            long long ans = tree[v].diffGcd;
            if (tree[v].secondMax != -INF) {
                ans = gcd(ans, tree[v].secondMax - tree[v].max);
            }
            if (tree[v].secondMin != INF) {
                ans = gcd(ans, tree[v].secondMin - tree[v].min);
            }
            ans = gcd(ans, tree[v].max);
            return ans;
        }
        pushToChildren(v, l, r);
        int mid = (r + l) / 2;
        return gcd(findGcd(2 * v, l, mid, ql, qr), findGcd(2 * v + 1, mid, r, ql, qr));
    }

    long long findGcd(int ql, int qr) {
        return findGcd(1, 0, n, ql, qr);
    }

    void print(){
        for(int i = 0;i<n;i++){
            cout<<findSum(i,i+1)<<" ";
        }
        cout<<endl;
    }
}sub,p;

const int maxn = 200007;
vector<int> st(maxn);
vector<int> depth(maxn);
vector<int> End(maxn);
vector<int> graph[maxn];
int Tm = 0;

void dfs(int u,int p = -1,int d = 0){
    st[u] = Tm++;
    depth[u] = d;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
    }
    End[u] = Tm-1;
}


signed main(){__
    int T = 1,n,root,u,v;
    cin>>T;
    while(T--){
        cin>>n>>root;
        root--;
        for(int i = 0;i<n;i++){
            graph[i].clear();
        }
        vector<int> q(n-1);
        for(auto &c:q)cin>>c;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Tm = 0;
        dfs(root);

        vector<int> subTree(n,1e9);
        vector<int> parent(n);
        subTree[0] = 0;

        // segTree sub;

        sub.build(subTree);
        p.build(parent);
        int ans = 1e9;
        for(int i = 0;i<n-1;i++){
            u = q[i];
            u--;

            int ancester = p.findSum(st[u],st[u]+1);
            int mxSub = sub.findMin(st[u],End[u]+1);
            
            int res = min(depth[u]-ancester,mxSub-depth[u]);

            // cout<<ancester<<" "<<mxSub<<" "<<depth[u]<<endl;

            p.updateMaxEq(st[u],End[u]+1,depth[u]);
            sub.updateEq(st[u],st[u]+1,depth[u]);

            ans = min(ans,res);
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}