#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int f(int n){
  int ans = 0;
  while(n){
    ans+=(n%10)*(n%10);
    n/=10;
  }
  return ans;
}

signed main(){__
    int T = 1,n;
    vector<int> pref;
    unordered_map<int,int> mp;

    for(int i = 0;i<=1000000;i++){
      set<int> st;
      st.insert(i);
      int x = i;
      while(1){
        int ans = f(x);
        if(st.count(ans))break;
        if(mp.count(ans)){
          st.insert(mp[ans]);
          break;
        }
        st.insert(ans);
        x = ans;
      }
      mp[i] = *(st.begin());
      pref.push_back(*(st.begin()));
    }

    int a,b;
    cin>>a>>b;
    int ans = 0;
    for(int i = a;i<=b;i++)
      ans+=pref[i];
    cout<<ans<<endl;
    return 0;
}