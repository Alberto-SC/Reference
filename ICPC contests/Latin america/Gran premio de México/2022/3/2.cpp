#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
vector<int> rev;
typedef vector<int>::iterator it;

vector<int> L;
vector<int> R;
vector<vector<long long>> mapLeft,sumLeft;
int newNode(){
  mapLeft.push_back({});
  sumLeft.push_back({});
  L.push_back(0);
  R.push_back(0);
  return mapLeft.size()-1;
}

int mn, mx;
int wavelet(it s,it e,int l,int r){
    int m = (l+r)>>1;
    int v = newNode();
    mapLeft[v].reserve(e-s+1);
    mapLeft[v].push_back(0);
    sumLeft[v].reserve(e-s+1);
    sumLeft[v].push_back(0);
    auto f = [m](int x){
        return x<=m;
    };
    for(it iter = s; iter!= e;iter++){
        mapLeft[v].push_back(mapLeft[v].back() + (*iter<=m));
        sumLeft[v].push_back(sumLeft[v].back() + (*iter<=m)*(rev[*iter]));
    }
    it p = stable_partition(s,e,f);
    if(l== r)return v;
    L[v] =  wavelet(s,p,l,m);
    R[v] =  wavelet(p,e,m+1,r);
    return v;
}
long long kthSum(int i,int j,int k){
  j++;
  int l = mn,r = mx,li,lj;
  long long si,sj;
  long long ans = 0;
  int u = 0;
  while(l!=r){
      int m = (l+r)>>1;
      li = mapLeft[u][i],lj = mapLeft[u][j];
      si = sumLeft[u][i],sj = sumLeft[u][j];
      if(k<= lj-li){
        u = L[u];
        i = li,j = lj, r = m;
      }
      else {
        ans+=(sj-si);
        u = R[u];
        i-=li,j-=lj,l = m+1,k-=(lj-li);
      }
  }
  ans+=rev[r]*k;
  return ans;
}




signed main(){__
  int n,k,l;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for(auto &c:a)cin>>c;
  for(auto &c:b)cin>>c,c*=-1;
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
  vector<int> u;
  vector<int> copy = b;
  sort(copy.begin(),copy.end());
  u.push_back(copy[0]);
  int last = u.back();
  for(int i = 1;i<copy.size();i++){
    if(copy[i]!=last){
      last = copy[i];
      u.push_back(last);
    }
  }
  rev.resize(u.size());
  for(int i = 0;i<b.size();i++){
    int idx = lower_bound(u.begin(),u.end(),b[i])-u.begin();
    rev[idx] = b[i];
    b[i] = idx;
  }

  mn = 0,mx = u.size()-1;
  wavelet(b.begin(),b.end(),mn,mx);
  
  long long ans = sum-kthSum(0,k-1,l);
  for(int i = k;i<2*n;i++){
    sum+=a[i];
    sum-=a[i-k];
    if(n-1<=i && n-1> i-k){
      
      ans = max(ans,sum-kthSum((i-k)+1,i,l));
    }
  }
  cout<<ans<<endl;

  return 0;
}

