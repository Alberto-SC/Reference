#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main(){__
  string s;
  while(cin>>s){
    int ans = 0;
    for(int j = 0;j<s.size();j++){
      vector<int> z = prefix_function(s.substr(j));
      int s = accumulate(z.begin(),z.end(),0);
      ans+=s;
    }
    cout<<ans<<endl;
  }
  return  0;
}


