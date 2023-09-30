#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n,x;
  cin>>T;
  while(T--){
    cin>>n;
  
    vector<pair<int,int>> q;
    for(int i = 1;i<n;i++){
      q.push_back({1,i+1});
    }
    pair<int,int> ans ;
    int last = 1;
    while(q.size()>1){
      int mx = 0;
      vector<int> pos[n+1];
      int mxcont = 0;
      bool flag = true;
      for(auto c:q){
        cout<<"? "<<c.first<<" "<<c.second<<endl;
        cin>>x;
        if(x>mx){
          mx = x;
          mxcont = 0;
        }
        else if(x ==mx)mxcont++;

        if(mxcont>n/2){
          flag = true;
        }
        pos[x].push_back(c.second);
      } 

      if(!flag){
        pos[1].clear();
        q.clear();
        for(int i = 2;i<n;i++){
          q.push_back({2,i+1});
        }
        for(auto c:q){
          cout<<"? "<<c.first<<" "<<c.second<<endl;
          cin>>x;
          if(x>mx){
            mx = x;
            mxcont = 0;
          }
          else if(x ==mx)mxcont++;

          if(mxcont>(n/2)+1){
            flag = false;
            break;
          }
          pos[x].push_back(c.second);
        } 
      }

      vector<pair<int,int>> nq;
      vector<int> nw;
      if(pos[mx].size()==1){
        nq.push_back({last,pos[mx][0]});
        q = nq;
        break;
      }
      for(int i = 1;i<pos[mx].size();i++){
        nq.push_back({pos[mx][0],pos[mx][i]});
      }
      q = nq;
    }

    cout<<"! "<<q[0].first<<" "<<q[0].second<<endl;

  }
  return 0;
}
