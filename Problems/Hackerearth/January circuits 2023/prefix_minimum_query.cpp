#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define MAXN 1000000
#define MAXPOWN 1048576		// 2^(ceil(log_2(MAXN)))
#define MAXLEV 21			// ceil(log_2(MAXN)) + 1
int n, P, Q;
pair<int,int> A[MAXPOWN];
pair<int,int> table[MAXLEV][MAXPOWN];
int maxlev, sz;

void build(int level=0,int l=0, int r=sz){
  int m = (l+r)/2;
  
  table[level][m] = A[m];
  for(int i=m-1;i>=l;i--)
    table[level][i] = min(table[level][i+1],A[i]);
    
  if(m+1 < r) {
    table[level][m+1] = A[m+1];
    for(int i=m+2;i<r;i++)
      table[level][i] = min(table[level][i-1],A[i]);
  }
  if(l + 1 != r)		// r - l > 1
  {
    build(level+1, l, m);
    build(level+1, m, r);
  }
}

pair<int,int> queryMn(int x, int y){
  if(x == y)
    return A[x];
  int k2 = __builtin_clz(x^y) ^ 31;
  int lev = maxlev - 1 - k2;
  auto ans = table[lev][x];
  if(y & ((1<<k2) - 1))	// y % (1<<k2)
    ans = min(ans,table[lev][y]);
  return ans;
}

inline int gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0){
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int subSquareSize = 1ll << (2*pow - 2);
	int ans = seg * subSquareSize;
	int add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
 
struct query{
	int l,r,id;int ord;
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
};
 
inline bool operator<(const query &a, const query &b) {
	return a.ord < b.ord;
}

int total = 0;

vector<int> ac;
vector<int> len;
vector<int> nums;
void addR(int r,int l){
    auto mn = queryMn(l,r);
    total+=mn.first;
}

void remR(int r,int l){
    auto mn = queryMn(l,r);
    total-=mn.first;
}

void addL(int l,int r){
    if(l+len[l]>r){
        total = nums[l]*((r-l)+1);
    }
    else{
        total-=ac[l+1]-(ac[l+len[l]]);
        total+=nums[l]*len[l];
    }
}

void remL(int l,int r){
    auto mn = queryMn(l+1,r);
    total = (ac[l+1]-ac[mn.second])+(nums[mn.second]*((r-mn.second)+1));
}

signed main(){__
    int T = 1,n,q,l,r;
    while(T--){
        cin>>n>>q;
        sz = n+2;
        maxlev = __builtin_clz(n+2) ^ 31;		// floor(log_2(n))
        if( (1<<maxlev) != n+2)
            sz = 1<<++maxlev;

        nums.resize(n+3);
        for(int i = 1;i<=n;i++){
            cin>>nums[i];
            A[i] = {nums[i],i};
        }

        build();
        
        ac.resize(n+2);
        len.resize(n+2);
        nums.push_back(0);

        stack<int> st;
    
        for(int i = 1;i<=n;i++)
            len[i] = (n+1)-i;

        for(int i = 1;i<=n;i++){
            while(st.size() && nums[st.top()]>nums[i]){
                len[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }

        while(st.size()){
            st.pop();
        }

        for(int i = n;i>=1;i--){
            ac[i] = (nums[i]*len[i])+ac[i+len[i]];
        }
   
        vector<query> Q;

        for(int id = 0;id<q;id++){
            cin>>l>>r;
            Q.push_back({l,r,id});
            Q.back().calcOrder();
        }

        sort(Q.begin(),Q.end());

        int L = 1,R = 0;
        vector<int> ans(q);
        for(int i = 0;i<q;i++){
            int l = Q[i].l;
            int r = Q[i].r;
            while(L>l){
                L--;
                addL(L,R);
            }
            while(R<r){
                R++;
                addR(R,L);
            }
            while(L<l){
                remL(L,R);
                L++;
            }
            while(R>r){
                remR(R,L);
                R--;
            }
            ans[Q[i].id] = total;
        }

        for(int i = 0;i<q;i++)
            cout<<ans[i]<<endl;
    }
    return 0;
}
