#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,k,l;
    cin>>n>>k>>l;
    string s,t;
    cin>>s;
    cin>>t;
    set<char> st(t.begin(),t.end());

    vector<int> idx;

    for(int i = 0;i<n;i++){
      if(st.count(s[i]))idx.push_back(i);
    }


    int ans = 0;
    for(int i = k-1;i<idx.size();i++){
      int L = i-(k-1);
      int left = L?idx[L]-idx[L-1]:idx[L]+1;
      int right = i+1<idx.size()?idx[i+1]-idx[i]:n-idx[i];
      // cout<<left<<" "<<right<<" "<<L<<endl;
      ans+=left*right;
    }
    cout<<ans<<endl;
    return 0;
}