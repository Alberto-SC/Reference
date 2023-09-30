#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s;
    cin>>s;

    int x = 0;
    int neg = s[0]== ')';

    int last = 0;
    vector<int> ans(n,1);
    int c1 = 0,c2 = 0;
    for(auto c:s){
      if(c=='(')c1++;
      else c2++;
    }
    if(c1 != c2){
      cout<<-1<<endl;
      continue;
    }

    for(int i = 0;i<n;i++){
      if(s[i]==')')x--;
      else x++;

      if(x>0 && neg){
        for(int j = last;j<i;j++)ans[j] = 2;
        last = i;
        neg = false;
      }
      if(x<0 && !neg){
        for(int j = last;j<i;j++)ans[j] = 1;
        last = i;
        neg = true;
      }
    }
    for(int i = last;i<n;i++){
      if(neg)ans[i] = 2;
      else ans[i] = 1;
    }

    set<int> st(ans.begin(),ans.end());
    cout<<st.size()<<endl;
    for(auto &c:ans){
      if(c == 2 && st.size() == 1)
        c = 1;
      cout<<c<<" ";
    }
    cout<<endl;
  }
  return 0;
}