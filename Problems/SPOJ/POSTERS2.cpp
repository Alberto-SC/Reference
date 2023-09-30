#include <bits/stdc++.h>
using namespace std;
  
int n;
vector<int>  lazy;

void propagate(int id) {
  if(lazy[id]) 
    lazy[2 * id] = lazy[2 * id + 1] = lazy[id];
  lazy[id] = 0;
}
 
void update(int x, int y, int color, int id = 1, int l = 0,int r = n){
  if(x >= r or l >= y)  return ;
  if(x <= l && r <= y){
    lazy[id] = color;
    return ;
  }
  int mid = (l+r)/2;
  propagate(id);
  update(x, y, color, 2 * id, l, mid);
  update(x, y, color, 2*id+1, mid, r);
}
 
set<int> ans;
void cnt(int id = 1,int l = 0, int r = n){
  if(lazy[id]){
    ans.insert(lazy[id]);
    return ; // there is no need to see the children, because all the interval is from the same color
  }
  if(r == l + 1) return ;
  int mid = (l+r)/2;
  cnt(2 * id, l, mid);
  cnt(2*id+1, mid, r);
}
 
int main() {
 
    int t; cin >> t;
    while(t--) {
    ans.clear();
    int x; cin >> x;
    set<int> pts;
    vector<pair<int,int>> ranges(x);
    for(int i = 0; i < x; i++) {
        int l, r; cin >> l >> r;
        pts.insert(l);
        pts.insert(r);
        ranges[i] = {l, r};
    }
 
    int k = 0;
    map<int, int> m;
    for(auto p: pts) 
        m[p] = k++;
 
    n = k; 
    for(int i = 0; i < x; i++) {
        ranges[i].first = m[ranges[i].first];
        ranges[i].second = m[ranges[i].second];
    }
    lazy.assign(4 * (k + 1), 0);
    for(int i = 0; i < x; i++) {
        update(ranges[i].first, ranges[i].second + 1, i + 1);
    }
    cnt();
    cout << ans.size() << "\n";
  }
  return 0;
}