#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 
 
 
struct Node {
  long long sum;
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
  roots.resize(arr.size()+1);
  newNode(0,0);
  for (int val : arr) mn = min(mn, val), mx = max(mx, val);
  for (int i = 0; i < (int)arr.size(); i++)
    roots[i + 1] = update(roots[i], mn, mx, arr[i]);
}

/* find kth smallest/greatest number among arr[l], arr[l+1], ..., arr[r]
 * k is 1-based, so find_kth(l,r,1) returns the min
 */

long long query(int vl, int vr, int tl, int tr, int k,bool mx){
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
long long query(int l, int r, int k,bool max_num = false){
  assert(1 <= k && k <= r - l + 1); 
  assert(0 <= l && r + 1 < (int)roots.size());
  return query(roots[l], roots[r + 1], mn, mx, k,max_num);
}



/* find **sum** of k smallest/greatest numbers among arr[l], arr[l+1], ..., arr[r]
 * k is 1-based, so find_kth(l,r,1) returns the min
 */

long long query_sum(int vl, int vr, int tl, int tr, int k,bool mx){
  if (tl == tr)
    return tl * k;
  int tm = (tl+tr)>>1;

  int lL  = LCH[vl], lR = RCH[vl], rL = LCH[vr],rR = RCH[vr];
  
  if(mx){
    swap(lL,lR),swap(rL,rR);
  }

  int left_count = cnt[rL] - cnt[lL];
  long long left_sum = sum[rL] - sum[lL];
  if (left_count >= k) return query_sum(lL, rL,mx?tm+1:tl, mx?tr:tm, k,mx);
  return left_sum + query_sum(lR, rR, mx?tl:tm + 1, mx?tm:tr, k - left_count,mx);
}

// Call this helper function  
long long query_sum(int l, int r, int k,bool max_sum = false){
  assert(1 <= k && k <= r - l + 1); //note this condition implies L <= R
  assert(0 <= l && r + 1 < (int)roots.size());
  return query_sum(roots[l], roots[r + 1], mn, mx, k,max_sum);
}
 

signed main(){__
  int n,k,l;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for(auto &c:a)cin>>c;
  for(auto &c:b)cin>>c;
  cin>>k>>l;
  a.resize(2*n);
  b.resize(2*n);
  for(int i = n;i<2*n;i++){
    a[i] = a[i-n];
    b[i] = b[i-n];
  }
  
  long long sum = 0;
  for(int i = 0;i<k;i++){
    sum+=a[i];
  }

  init(b);
  
  long long ans = sum+query_sum(0,k-1,l,true);
 
  for(int i = k;i<2*n;i++){
    sum+=a[i];
    sum-=a[i-k];
    if(n-1<=i && n-1> i-k){
      
      ans = max(ans,sum+query_sum((i-k)+1,i,l,true));
    }
  }
  cout<<ans<<endl;

  return 0;
}
