#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int main(){__
  int a,b,c,d;
  freopen("paint.in","r",stdin);
  freopen("paint.out","w",stdout);
  cin>>a>>b>>c>>d;
  vector<bool> used(107);
  for(int i =a;i<b;i++)
    used[i] = true;
  for(int i =c;i<d;i++)
    used[i] = true;
  int ans = 0;
  for(int i = 0;i<=100;i++)
    ans+=used[i];
  cout<<ans<<endl;
  return 0;
}
