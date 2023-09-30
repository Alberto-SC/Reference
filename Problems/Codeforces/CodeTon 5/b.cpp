#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,z;
    cin>>T;
    while(T--){
        cin>>n>>z;
        vector<int> a(n),b(n),c(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        for(auto &x:c)cin>>x;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        reverse(c.begin(),c.end());
        
        int x = 0;
        while(1){
          if(a.size() && ((a.back()&z) == a.back())){
            x |=a.back();
            a.pop_back();
            continue;
          }
          if(b.size() && ((b.back()&z) == b.back())){
            x |=b.back();
            b.pop_back();
            continue;
          }
          if(c.size() && ((c.back()&z) == c.back())){
            x |=c.back();
            c.pop_back();
            continue;
          }
          break;
        }

        if(x == z)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}