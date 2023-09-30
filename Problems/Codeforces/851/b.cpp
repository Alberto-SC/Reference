#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int f(int x){
  int sum = 0;
  while(x){
    sum+=x%10;
    x/=10;
  }
  return sum;
}

signed main(){__
  int T,n;
  cin>>T;
  while(T--){
    cin>>n;
    string s = to_string(n);
    string x = s;
    string y = s;

    bool g = false;
    for(int i = 0;i<s.size();i++){
      int ds = s[i]-'0';
      int dx = ds/2;
      int dy = ds-dx;

      if(ds&1){
        if(!g) x[i] = char(dy+'0'),y[i] = char(dx+'0');
        else x[i] = char(dx+'0'),y[i] = char(dy+'0');
        g = !g;
      }
      else {
        x[i] = char(dx+'0');
        y[i] = char(dy+'0');
      }
    }
    cout<<stoll(x)<<" "<<stoll(y)<<endl;
  }
  return 0;
}
