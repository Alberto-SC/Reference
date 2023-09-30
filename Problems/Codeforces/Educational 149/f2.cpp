#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

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
 


bool check(int x,int n,int k){
  int last = 0;
  for(int i = 1;i<n;i++){
    if(query_sum(0,i-1,last+1)<=x)last++;
    if(n-i<k-last)continue;
    if(query_sum(i,n-1,k-last)<=x)return true;
  }

  return false;
}


signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        init(nums);
        int r = query_sum(0,n-1,k);
        int l = 0;

        while(l+1<r){
          int m = (l+r)>>1;
          if(check(m,n,k))r = m;
          else l = m;
        }
        // check(wt,52,n,k);
        cout<<r<<endl;
          
    }
    return 0;
}