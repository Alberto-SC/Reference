#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int sum(int x){
  return (x*(x+1)/2);
}

int sum2(int x){
  return (x*(x+1)*((2*x)+1))/6;
}

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> pos(n);
    for(int i = 0;i<n;i++){
      pos[nums[i]] = i;
    }

    int l = pos[0];
    int r = pos[0];
    int ans = 1;
    if(n==1){
      cout<<1<<endl;
      continue;
    }
    set<int> st;
    for(int i = 1;i<n;i++)
      st.insert(i);


    int k = *st.begin();
    int cont = 10;
    while((l>0 || r<n-1) && cont--){
      int lenR ,lenL;
      if(pos[k]>r){
        lenR = (pos[k]-r)-1;
        lenL = l;
      }
      else{
        lenL = (l-pos[k])-1;
        lenR = (n-1)-r;
      }
      int len= (r-l)+1;
      int need = max((2*k)-len,0ll);
      lenR = min(lenR,need);
      lenL = min(lenL,need);

      //cout<<l<<" "<<r<<" "<<lenL<<" "<<lenR<<" "<<k<<" "<<" "<<len<<" "<<need<<endl;
      
      if(len<=2*k){
        //ans+= lenR+1;
        int y = max(need-lenR,0ll);
        int z = min(y,lenL);
        //ans+= z*(lenR+1);
        
        //cout<<y<<" "<<z<<" "<<ans<<endl;
        //ans+= sum(need-z);
        //cout<<ans<<endl;
        //ans-= sum(need-lenL);
      }
      need = 2*k;
      if(pos[k]>r){
        for(int i = r;i<=pos[k];i++){
          st.erase(nums[i]);
          if(i<pos[k]){
            int Len = (i-l)+1;
            if(Len<=need)
              ans+= min(need-Len,lenL)+1;
          }
        }
        r = pos[k];
        k = *st.begin();
      }
      else{
        for(int i = l;i>=pos[k];i--){
          st.erase(nums[i]);
          if(i>pos[k]){
            int Len = (r-i)+1;
            if(Len<=need)
              ans+= min(need-Len,lenR)+1;
          }
        }
        l = pos[k];
        k = *st.begin();
      }
      //cout<<ans<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}
