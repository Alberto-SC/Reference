#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> p_function(const vector<int>& v){
    int n = v.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && v[j] != v[i]){
            j = p[j - 1];
        }
        if(v[j] == v[i])
            j++;
        p[i] = j;   
    }
    return p;
}
int match(const vector<int>& s, const vector<int>& pat) {
    int n = pat.size();
    int m = s.size();
    if(m<n){
        cout<<endl;
        return false;
    }
    vector<int> match;
    for(auto c:pat)match.push_back(c);
    match.push_back(1e15);
    for(auto c:s)match.push_back(c);

    vector<int> kmp =p_function(match);
    int ans = 0;
    for(int i = 0; i < m - n + 1; i++){   
        if(kmp[2 * n + i] == n){   
          ans++;
        }
    }
    return ans;
}

signed main(){__
  int T = 1,m,n;
  cin>>m>>n;
  vector<int> a(m);
  for(auto &c:a)cin>>c;
  vector<int> b(n);
  for(auto &c:b)cin>>c;

  vector<int> da,db;
  for(int i = 1;i<m;i++)
    da.push_back(a[i]-a[i-1]);

  for(int i = 1;i<n;i++)
    db.push_back(b[i]-b[i-1]);

  cout<<match(db,da)<<endl;
  return 0;
}