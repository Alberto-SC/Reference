#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


signed main(){__
  int T = 1,n,q,l,r,t;
  cin>>n>>q;
  vector<int> nums(n);
  ordered_set st;
  int N = n;
  for(auto &c:nums)cin>>c,st.insert(c);

  while(q--){
    cin>>t;
    if(t==1){
      cin>>l;
      int order = st.order_of_key(l);
      int num = *st.find_by_order(order);
      if(num == l){
        continue;
      }
      else if(st.order_of_key(l)==N)st.insert(l),N++;
      else {
        int x = *st.lower_bound(l);
        st.erase(st.find_by_order(st.order_of_key(x)));
        st.insert(l);
      }

    }
    else{
      cin>>l>>r;
      int L = st.order_of_key(l);
      int R = st.order_of_key(r+1);
      cout<<R-L<<endl;
    }
  }

  return 0;
}