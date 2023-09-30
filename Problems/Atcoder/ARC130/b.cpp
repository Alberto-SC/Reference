#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

struct Q{
  int t,r,c;
};

signed main(){__
  int h,w,c,q,t,r,cl;
  cin>>h>>w>>c>>q;
    
  vector<int> ans(c+1);
  map<int,bool> col;
  map<int,bool> row;
  
  vector<Q> querys;
  for(int i = 0;i<q;i++){
    cin>>t>>r>>cl;
    querys.push_back({t,r,cl});
  }
  for(int i = q-1;i>= 0;i--){
    if(querys[i].t==1){
      if(!row.count(querys[i].r))ans[querys[i].c]+=w-col.size();
      row[querys[i].r] = true;
    }
    else{
      if(!col.count(querys[i].r))ans[querys[i].c]+=h-row.size();
      col[querys[i].r] = true;
    }
    
  }
  for(int i = 1;i<=c;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;  
}
