#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,t,q;
  cin>>T;
  while(T--){
    string s1,s2;
    cin>>s1>>s2;
    n = s1.size();
    cin>>t>>q;

    set<pair<int,int>> st;

    vector<int> lastBlock(n,-(t+1));

    for(int i = 0;i<n;i++){
      if(s1[i]!=s2[i])
        st.insert({lastBlock[i],i});
    }
    int Tm = 0;
    while(q--){

      int type,id,ids1,ids2,pos1,pos2;
      cin>>type;
      if(type ==1){
        cin>>id;
        id--;
        if(s1[id]!=s2[id])st.erase({lastBlock[id],id});
        lastBlock[id] = Tm;
        if(s1[id]!=s2[id])st.insert({lastBlock[id],id});
      } 
      else if(type ==2){
        cin>>ids1>>pos1>>ids2>>pos2;

        pos1--,pos2--;
        st.erase({lastBlock[pos1],pos1});
        st.erase({lastBlock[pos2],pos2});

        if(ids1 == 1 && ids2 == 1)
          swap(s1[pos1],s1[pos2]);
        if(ids1 == 1 && ids2 == 2)
          swap(s1[pos1],s2[pos2]);
        if(ids1 == 2 && ids2 == 1)
          swap(s2[pos1],s1[pos2]);
        if(ids1 == 2 && ids2 == 2)
          swap(s2[pos1],s2[pos2]);

        if(s1[pos1]!=s2[pos1])st.insert({lastBlock[pos1],pos1});
        if(s1[pos2]!=s2[pos2])st.insert({lastBlock[pos2],pos2});
      }
      else{
        if(st.size()==0)cout<<"YES"<<endl;
        else{
          int mn = st.begin()->first;
          if(mn+t>Tm)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
        }
      }

      Tm++;
    }

  }
  return 0;
}