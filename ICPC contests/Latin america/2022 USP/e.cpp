#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define printD(A) for(auto c:A)cout<<c<<" ";
#define int long long 

vector<deque<int>> st;
vector<int> lazy1;
vector<int> lazy2;
const int maxn = 1000007;
int phi[maxn];
int n;
deque<int> merge(deque<int> a,deque<int> b){
  deque<int> ans;
  for(int i = 0;i<20;i++){
    ans.push_back(a[i]+b[i]);
  }
  return ans;
}

void propagate(int v,int l,int r){
  if(!lazy1[v]&& !lazy2[v])return;
  if(lazy1[v]){
    int L = (r-l)+1;
    deque<int> nw; 
    int x = lazy1[v];
    while(x>1){
      nw.push_back(x*L);
      x= phi[x];
    }
    while(nw.size()<20){
      nw.push_back(L);
    }
    st[v] = nw;
    if(l!= r){
      lazy1[v<<1] = lazy1[v];
      lazy1[v<<1|1] = lazy1[v];
      lazy2[v<<1] = 0;
      lazy2[v<<1|1] =0;
    }
  } 
  if(lazy2[v]){
    int times = lazy2[v];
    while(times--){
      int x = st[v].front();
      if(x ==1)break;
      st[v].pop_front();
      st[v].push_back(1);
    }
    if(l!= r){
      lazy1[v<<1] = lazy1[v];
      lazy1[v<<1|1] = lazy1[v];
      lazy2[v<<1] += lazy2[v];
      lazy2[v<<1|1]+=lazy2[v];
    }
  }
  lazy1[v] = 0;
  lazy2[v]= 0;
}

void update(int l,int r,int type,int x,int v = 1,int sl = 0,int sr =n-1){
  propagate(v,sl,sr);
  if(sl> r || sr <l || sl>sr) return ;
  if(sl>=l && sr<=r){
    if(type==1){
      lazy2[v]++;
    }
    else{
      lazy1[v] = x;
      lazy2[v] = 0;
    }
    propagate(v,sl,sr);
    return ;
  }
  
  int m = (sl+sr)>>1;
  update(l,r,type,x,v<<1,sl,m);
  update(l,r,type,x,v<<1|1,m+1,sr);
  st[v] = merge(st[v<<1],st[v<<1|1]);
  
}
deque<int> zero;

deque<int> query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
  propagate(v,sl,sr);
  if(sl>r || sr<l || sl>sr)return zero;
  if(sl>=l && sr<=r)return st[v];
  int m = (sl+sr)>>1;
  return merge(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

vector<bool> composite(maxn);
vector<int> primes;
void sieve(){
  fill(composite.begin(),composite.end(),false);
  phi[1] = 1;
  for(int i = 2;i<maxn;i++){
    if(!composite[i]){
      phi[i] = i-1;
      primes.push_back(i);
    }
    for(int j = 0;j<primes.size() && i*primes[j]<maxn;j++){
      composite[i*primes[j]] = true;
      if(i%primes[j]==0){
        phi[i*primes[j]] = phi[i]*primes[j];
        break;
      }
      else{
        phi[i*primes[j]] = phi[i]*phi[primes[j]];
      }
    }
  }
}

void print(){
  for(int i = 0;i<n;i++){
    deque<int> d = query(i,i);
    cout<<d[0]<<" ";
  }
  cout<<endl;
}

signed main(){__
  int q,t,l,r,x;
  cin>>n>>q;
  st.resize(4*n);
  lazy1.resize(4*n);
  lazy2.resize(4*n);
  int mx = 0;
  sieve();
  for(int i= 0;i<20;i++){
    zero.push_back(0);
  }

  vector<int> nums(n);
  for(auto &c:nums)cin>>c;
  for(int i = 0;i<n;i++){
    update(i,i,2,nums[i]);
  }
  while(q--){
    cin>>t>>l>>r;
    l--,r--;
    if(t ==1){
      update(l,r,1,1); 
    }
    else if(t ==2){
      cin>>x;
      update(l,r,2,x);
    }
    else {
      deque<int> ans = query(l,r);
      cout<<ans[0]<<endl;
    }
  }
  return 0;  
}


