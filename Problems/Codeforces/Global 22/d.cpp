#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> inDegree(maxn);
vector<int> outDegree(maxn);

vector<int> order;

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int l = 0,r = n;
    order.clear();
    for(int i = 0;i<=n;i++){
      graph[i].clear();
      inDegree[i] = 0;
      outDegree[i] = 0;
    }
    for(int i = 0;i<n;i++){
      if(nums[i]==0){
        r = min(r,i+1);
        continue;
      }
      if(nums[i]== n+1){
        l = max(l,i+1);
        continue;
      }


      graph[nums[i]].push_back(i+1);
      inDegree[i+1]++;
      outDegree[nums[i]]++;
      l = max(l,min(nums[i],i+1));
      r = min(r,max(nums[i],i+1));
    }

    for(int i = 1;i<=n;i++){
      if(inDegree[i]==0 && outDegree[i]==0)order.push_back(i);
    }
    for(int i = 1;i<=n;i++){
      if(inDegree[i]==0 && outDegree[i]){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
          int u = q.front();
          q.pop();
          order.push_back(u);
          vector<int> next;
          for(auto v:graph[u]){
            next.push_back(v);
          }
          sort(next.begin(),next.end(),[&](int a,int b){
              return outDegree[a]<outDegree[b];
          });
          for(auto c:next)q.push(c);
        }
      }
    }
    cout<<l<<endl;
    for(auto c:order)cout<<c<<" ";
    cout<<endl;
  }

  return 0;
}

