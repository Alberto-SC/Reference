#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,x;
  vector<int> vis(1000007,-1);

  vector<int> v;
  int k = 1024;

  int Cont = 0;
  while(1){
    cin>>x;
    Cont++;
    if(vis[x]!=-1)break;
    if(Cont >2020){
      cout<<"! -1"<<endl;
    }
    else if(Cont > 1000){
      k = -1;
      cout<<"- 1"<<endl;
    }
    else
      cout<<"+ "<<k<<endl;

    vis[x] = v.size();
    v.push_back(k);
  }

  int ans = 0;
  for(int i = vis[x];i<v.size();i++)
    ans+=v[i];

  int last = x,x1,x2,res = ans;

  for(int i = 1;i*i<=ans;i++){
    if(ans%i==0){
      cout<<"+ "<<i<<endl;
      cin>>x1;
      if(x1 == last){
        res = i;
        break;
      }
      else{
        cout<<"- "<<i<<endl;
        cin>>x2;
      }
      if(ans/i !=i){
        cout<<"+ "<<ans/i<<endl;
        cin>>x1;
        if(x1 == last)
          res = min(res,ans/i);
        else{
          cout<<"- "<<ans/i<<endl;
          cin>>x2;
        }
      }
    }
  }
  cout<<"! "<<res<<endl;
  return 0;
}