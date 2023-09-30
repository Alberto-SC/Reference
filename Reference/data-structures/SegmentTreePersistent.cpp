#include <bits/stdc++.h>                                        // exclude-line
using namespace std;                                            // exclude-line
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);      // exclude-line
#define int long long                                           // exclude-line 
#define endl '\n'                                               // exclude-line

/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: A persistent data structure is a data structure that remembers 
 * it previous state for each modification. This allows to access any version of this data 
 * structure that interest us and execute a query on it.
 * Time: O(\log N) per query.
 */

const int maxn = 800007;
int L[maxn],R[maxn],st[maxn],lazy[maxn],N;
int n; /*+ Must be global for default values in functions */

int newLeaf(int val){
    int p = ++N;
    L[p] = R[p] = 0;
    st[p] = val;
    return p;
}

int newParent(int l,int r){
    int p = ++N;
    L[p] = l;
    R[p] = r;
    st[p] = st[l]+st[r];
    return p;
}

int newLazy(int v,int val,int l,int r){
    int p = ++N;
    L[p] = L[v];
    R[p] = R[v];
    lazy[p] += val;
    st[p] = st[v]+((r-l)+1)*val;
    return p;
} 

int build(vector<int> &A,int l = 0,int r = n-1){
    if(l== r)return newLeaf(A[l]);
    int mid = (l+r)>>1;
    return newParent(build(A,l,mid),build(A,mid+1,r));
}

void propagate(int p,int l,int r){
    if(lazy[p]==0)return;
    if(l!= r){
        int mid = (l+r)>>1;
        L[p] = newLazy(L[p],lazy[p],l,mid);
        R[p] = newLazy(R[p],lazy[p],mid+1,r);
    }
    lazy[p] = 0;
}

int update(int l,int r,int val,int p,int sl = 0 ,int sr = n-1){
    if(sr<l || sl>r)return p;
    if(sl>=l && sr<=r)return newLazy(p,val,sl,sr);
    propagate(p,sl,sr);
    int mid = (sl+sr)>>1;
    return newParent(update(l,r,val,L[p],sl,mid),update(l,r,val,R[p],mid+1,sr));
}

int query(int l,int r,int p,int sl = 0,int sr = n-1){
    if(sr<l || sl> r)return 0;
    if(sl>=l && sr<=r)return st[p];
    int mid = (sl+sr)>>1;
    propagate(p,sl,sr);
    return query(l,r,L[p],sl,mid)+query(l,r,R[p],mid+1,r);
}

// ------------------- 

struct Vertex {
    Vertex *l, *r;
    ll sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l -> sum;
        if (r) sum += r -> sum;
    }
};
 
struct persistentSegmentTree {
    int n;
    Vertex* build(vll &nums, int tl, int tr) {
        if (tl == tr) return new Vertex(nums[tl]);
        int mid = (tl + tr) / 2;
        return new Vertex(build(nums,tl,mid),build(nums,mid+1,tr));
    }
 
    Vertex *build(vll &nums){
        n = nums.size();
        return build(nums,0,n-1);
    }
 
    int query(Vertex *v, int l, int r) {
        return query(v,0,n-1,l,r);
    }
 
    ll query(Vertex *v, int tl, int tr, int l, int r) {
        if (tl > r || tr < l) return 0;
        if (tl >= l && tr <= r) return v -> sum;
        int mid = (tl + tr) / 2;
        return query(v -> l, tl,mid,l,r) + query(v -> r,mid+1,tr,l,r);
    }
 
    Vertex* update(Vertex *v, int tl, int tr, int pos, int val) {
        if (tl == tr) return new Vertex(val);
        int mid = (tl + tr) / 2;
        if (pos <= mid) return new Vertex(update(v -> l,tl,mid,pos,val), v -> r);
        return new Vertex(v -> l, update(v -> r, mid + 1, tr, pos ,val));
    }
 
    Vertex* update(Vertex *v, int pos, ll val) {
        return update(v,0,n-1,pos,val);
    }
 
    int find_kth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
        if (tl == tr)
            return tl;
        int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
        if (left_count >= k)
            return find_kth(vl->l, vr->l, tl, tm, k);
        return find_kth(vl->r, vr->r, tm+1, tr, k-left_count);
    }
};
 

// kth sum in range
struct Node {
  int sum;
  int cnt;
  int L, R;
};

vector<int> sum;
vector<int> cnt;
vector<int> LCH;
vector<int> RCH;

int newNode(int val,int c,int l = 0,int r = 0){
  sum.push_back(val);
  cnt.push_back(c);
  LCH.push_back(l);
  RCH.push_back(r);
  return sum.size()-1;

}

int mn, mx;
vector<int> roots;

int update(int v, int tl, int tr, int idx) {
  if (tl == tr) {
    return newNode(sum[v]+tl,cnt[v]+1);
  }
  int tm = tl + (tr - tl) / 2;
  int L = LCH[v];
  int R = RCH[v];
  if (idx <= tm)
    L = update(L, tl, tm, idx);
  else
    R = update(R, tm + 1, tr, idx);
  return newNode(sum[L]+sum[R],cnt[L]+cnt[R],L,R);
}


void init(const vector<int>& arr){
  roots.clear();
  sum.clear();
  cnt.clear();
  LCH.clear();
  RCH.clear();
  mn = 0;
  mx = 0;

  roots.resize(arr.size()+1);
  newNode(0,0);
  for (int val : arr) mn = min(mn, val), mx = max(mx, val);
  for (int i = 0; i < (int)arr.size(); i++)
    roots[i + 1] = update(roots[i], mn, mx, arr[i]);
}

/* find kth smallest/greatest number among arr[l], arr[l+1], ..., arr[r]
 * k is 1-based, so find_kth(l,r,1) returns the min
 */

int query(int vl, int vr, int tl, int tr, int k,bool mx){
  if (tl == tr)
    return tl;
  int tm = tl + (tr - tl) / 2;
  int lL  = LCH[vl], lR = RCH[vl], rL = LCH[vr],rR = RCH[vr];
    //^ first l is for range, L is Left child , same for r, 

  if(mx){
    swap(lL,lR),swap(rL,rR);
  }

  int left_count = cnt[rL] - cnt[lL];
  if (left_count >= k) return query(lL, rL,mx?tm+1: tl, mx?tr:tm, k ,mx);
  return query(lR, rR, mx?tl:tm + 1, mx?tm:tr, k - left_count,mx);
}

// Call this helper function
int query(int l, int r, int k,bool max_num = false){
  assert(1 <= k && k <= r - l + 1); 
  assert(0 <= l && r + 1 < (int)roots.size());
  return query(roots[l], roots[r + 1], mn, mx, k,max_num);
}


/* find **sum** of k smallest/greatest numbers among arr[l], arr[l+1], ..., arr[r]
 * k is 1-based, so find_kth(l,r,1) returns the min
 */
int query_sum(int vl, int vr, int tl, int tr, int k,bool mx){
  if (tl == tr)
    return tl * k;
  int tm = (tl+tr)>>1;

  int lL  = LCH[vl], lR = RCH[vl], rL = LCH[vr],rR = RCH[vr];
  
  if(mx){
    swap(lL,lR),swap(rL,rR);
  }

  int left_count = cnt[rL] - cnt[lL];
  int left_sum = sum[rL] - sum[lL];
  if (left_count >= k) return query_sum(lL, rL,mx?tm+1:tl, mx?tr:tm, k,mx);
  return left_sum + query_sum(lR, rR, mx?tl:tm + 1, mx?tm:tr, k - left_count,mx);
}

// Call this helper function  
int query_sum(int l, int r, int k,bool max_sum = false){
  assert(1 <= k && k <= r - l + 1); //note this condition implies L <= R
  assert(0 <= l && r + 1 < (int)roots.size());
  return query_sum(roots[l], roots[r + 1], mn, mx, k,max_sum);
}
 
