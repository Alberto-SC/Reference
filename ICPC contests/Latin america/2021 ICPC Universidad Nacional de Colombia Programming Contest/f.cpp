#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int mod(int a,int n){
  int x = a%n;
  if(x<0)x+=n;
  return x;
}

signed main(){__
  int n,q,t,r,c;
  char x,b;
  cin>>n>>q;
  vector<int> row(n);
  vector<int> col(n);
  vector<string> C(n);
  int ans = 0;
  for(int i = 0;i<n;i++){
    for(int j =0;j<n;j++){
      cin>>x;      
      if(x=='1'){
        row[i]++;
        col[j]++;
      }
      if(row[i]==n)ans++;
      if(col[j]==n)ans++;
      C[j].push_back(x);
    }
  }
  
  int off = 0;
  while(q--){
    cin>>t;
    if(t==1){
      cin>>r>>c>>b;
      r--,c--;
      char last = C[mod(c-off,n)][r];
      if(b=='0' && last=='1'){
        if(row[r]==n)ans--;
        if(col[c]==n)ans--;
        row[r]--;
        col[c]--;
      }
      else if(b=='1' && last=='0'){
        row[r]++;
        col[c]++;
        if(row[r]==n)ans++;
        if(col[c]==n)ans++;
      }
      C[mod(c-off,n)][r] = b;
    }
    else{
      cin>>b;
      int aux = col[n-1];
      vector<int> nwcol(n);
      for(int i = 1;i<n;i++){
        nwcol[i] = col[i-1];
      }
      col = nwcol;
      char last = C[mod((n-1)-off,n)][0];
    
      for(int i = 0;i<n;i++){
        int last = C[mod(0-off,n)][i]-'0';
        int nw = i?C[mod(0-off-1,n)][i-1]-'0':b-'0';
        bool flag = row[i]==n;
        row[i]+=nw;  
        row[i]-=C[mod(0-off-1,n)][i]-'0';
        if(flag && row[i]!=n)ans--;
        else if(!flag && row[i]==n)ans++;
      }
      string nwC = string(n,'a');
      for(int i = 1;i<n;i++){
        nwC[i]=C[mod(0-(off+1),n)][i-1];
      }
      C[mod(0-(off+1),n)] = nwC;
      C[mod(0-(off+1),n)][0] = b;
      int cont = 0;
      for(int i = 0;i<n;i++){
        if(C[mod(0-(off+1),n)][i]=='1')cont++;
      }
      col[0] = cont;
      if(aux==n && cont!=n)ans--;
      if(aux!=n && cont==n)ans++;
      off++;
    }
    cout<<ans<<endl;
  }

  return  0;
}

