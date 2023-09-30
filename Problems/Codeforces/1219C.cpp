#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int l;
  string s;
  cin>>l;
  cin>>s;
  if(l>s.size()){
    cout<<1<<string(l-1,'0')<<endl;
  }
  else if(l == s.size()){
    string x =string(l,'9');
    if(x == s){
      string ans = "1"+string(l-1,'0');
      ans+=ans;
      cout<<ans<<endl;
    }
    else{
      int idx = s.size()-1;
      while(s[idx]=='9'){
        s[idx] = '0';
        idx--;
      }
      s[idx]++;
      cout<<s<<endl;
    }
  }
  else{
    if(s.size()%l){
      string ans = "1"+string(l-1,'0');
      int mul = s.size()/l;
      mul++;
      for(int i = 0;i<mul;i++)
        cout<<ans;
      cout<<endl;
    }
    else{
      string ans = s.substr(0,l);
      int idx = l;
      while(s[idx]== s[idx%l]){
        idx++;
      }
      if(idx == s.size() || s[idx]>s[idx%l]){
        int id = ans.size()-1;
        while(id>=0 &&ans[id]=='9'){
          ans[id] = '0';
          id--;
        }
        int mul = s.size()/l;
        if(id==-1){
          ans = "1"+string(l-1,'0'); 
          mul++;
        }
        else{
          ans[id]++;
        }
        for(int i = 0;i<mul;i++)
          cout<<ans;
        cout<<endl;
      }
      else{
        int mul = s.size()/l;
        for(int i = 0;i<mul;i++)
          cout<<ans;
        cout<<endl;
      }

    }
  }
  return  0;
}
