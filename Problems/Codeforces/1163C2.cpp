#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define int long long 

signed main(){__
  int n,x,y;
  cin>>n;
  vector<pair<int,int>> p;

  for(int i = 0;i<n;i++){
    cin>>x>>y;
    p.push_back({x,y});
  }

  map<pair<int,int>,set<int>> D;
  map<int,int> H;
  map<int,int> V;
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      pair<int,int> a = p[i],b = p[j];
      int A = a.second-b.second;
      int B = a.first-b.first;
      int gcd = __gcd(A,B);
      A/=gcd;
      B/=gcd;
      int C = (A*a.first) - (B*a.second);
      if(A ==0)H[a.second]++;
      else if(B==0)V[a.first]++;
      else{
        D[{A,B}].insert(C);
      }
    }
  }
  int Ds = 0;
  for(auto c:D){
    Ds+=c.second.size();
  }
  int total = Ds+H.size()+V.size();
  int ans = 0;
  for(auto c:D){
    ans += (total-c.second.size())*c.second.size();
  }
  ans += H.size() * (total-H.size());
  ans += V.size() * (total-V.size());
  cout<<ans/2<<endl;

  return 0;
}
