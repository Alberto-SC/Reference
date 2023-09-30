#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

pair<int,int> getNum(int i,string &s){
  int j = i;
  int C = 1;
  if(s[i]=='-' || s[i]=='+'){
    j++;
    while(j<s.size() && s[j]<='9' &&s[j]>='0'){
      j++;
    }
    if(j!=i+1){
      C = stoll(s.substr(i,j-i));
    }
    else{
      if(s[i]=='-')C=-1;
    }
  }
  else{
    while(j<s.size() && s[j]<='9' && s[j]>='0'){
      j++;
    }
    if(j>i){
      C = stoll(s.substr(i,j-i));
    }
  }
  return {C,j};
}

signed main(){__
  int n;
  string s;
  cin>>s;
  vector<int> pws(200);
  vector<int> pwsN(200);
  for(int i = 0;i<s.size();){
    int C= 1,E = 1;
    if(s[i]=='x'){
      i++;
    }
    else{
      auto p = getNum(i,s);
      C = p.first;
      i = p.second;
      if(s[i]=='x'){
        i++;
      }
      else{
        pws[0]+=C;
        continue;
      }
    }
    if(s[i]!='^'){
      pws[1]+=C;
      continue;
    }
    else{
      i++;
      auto p = getNum(i,s);
      E = p.first;
      i = p.second;
    }
    if(E<0)
      pwsN[abs(E)]+=C;
    else
    pws[E]+=C;
  }

  vector<int> D(200);
  vector<int> DN(200);
  for(int i = 1;i<pwsN.size();i++){
    DN[i+1] = -i* pwsN[i];
  }
  for(int i = 1;i<pws.size();i++){
    D[i-1] = i* pws[i];
  }
  bool first = false;
  for(int i = 199;i>=0;i--){
    if(DN[i]){
      if(DN[i]>0 && first)cout<<"+";
      if(i>1) 
        cout<<DN[i]<<"x"<<"^-"<<i;
      else if(i==1)
        cout<<DN[i]<<"x";
      else cout<<DN[i];
      first = true;
    }
  }
  for(int i = 0;i<200;i++){
    if(D[i]){
      if(D[i]>0 && first)cout<<"+";
      if(i>1){
        cout<<D[i]<<"x"<<"^"<<i;
      }
      else if(i==1)
        cout<<D[i]<<"x";
      else cout<<D[i];
      first= true;
    }
  }
  if(!first)cout<<0<<endl;
  cout<<endl;
  return  0;
}

