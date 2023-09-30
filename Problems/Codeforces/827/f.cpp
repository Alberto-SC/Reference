#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){__
  int T,n,t,x;
  cin>>T;
  while(T--){
    cin>>n;
    vector<int> fa(26);
    vector<int> fb(26);
    string s;
    int a = 1,b = 1;
    fa[0]++;
    fb[0]++;
    set<char> st1,st2;
    while(n--){
      cin>>t;
      cin>>x;
      cin>>s;
      if(t ==1){
        for(auto c:s){
          fa[c-'a']+=x;
          st1.insert(c);
        }  
        a+=s.size()*x;
      }
      else{
        for(auto c:s){
          fb[c-'a']+=x;
          st2.insert(c);
        }
        b+=s.size()*x;
      }

      int ac = 0,ac2 = 0 ;
      bool flag = false;
      for(int i = 0;i<26;i++){
        ac+=fb[i];
        ac2+=fa[i];
        if(b-ac && ac2){
          flag = true;
          break;
        }
      }
      if(flag){
        cout<<"YES"<<endl;
      }
      else{
        if(st2.size()>1){
          cout<<"NO"<<endl;
        }
        else{
          char a1 = *st1.begin(),b1  = *st2.begin();
          if(b1<a1)cout<<"NO"<<endl;
          else if(fa[a1-'a']>=fb[b1-'a'])cout<<"NO"<<endl;
          else{
            if(st1.size()>1)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
          }
        }
      }
    }
  }
  return 0;
}

