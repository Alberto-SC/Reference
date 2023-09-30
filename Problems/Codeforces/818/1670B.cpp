#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s;
    cin>>s;
    int k;
    cin>>k;
    set<char> st;
    for(int i =0;i<k;i++){
      char x;
      cin>>x;
      st.insert(x);
    }
    int ans = 0;
    for(int i = 0;i<n;){
      int l = i;
      while(l<n && !st.count(s[l])){
        l++;
      }
      if(l==n)break;
      if(l ==i){
        i++;
        continue;
      }
      ans = max(ans,l-i);
      
      i = l;
    }
    cout<<ans<<endl;
  }
  return 0;
}


