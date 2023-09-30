#include <bits/stdc++.h>
using namespace std;
//#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

typedef tree<int, null_type, less_equal<int>, 
			rb_tree_tag, 
			tree_order_statistics_node_update> 
	ordered_set; 

signed main(){__
    long long t,n;
    string s = "abcdefghijklm";
    vector<long long> factorials;
    factorials.push_back(1);
    factorials.push_back(1);
    for(int i = 2;i<=15;i++)
        factorials.push_back(factorials.back()*i);
    cin>>t;
    while(t--){
        cin>>n;
        n--;
        vector<int> ans;
        ordered_set st;
        int x = s.size()-1;
        for(int i = 0;i<13;i++)
            st.insert(i);
        while(n){
            long order = n/factorials[x];
            n = n-(order*factorials[x]);
            ans.push_back(*st.find_by_order(order));
            st.erase(st.find_by_order(order));
            x--;
        }
        while(st.size()){
            ans.push_back(*st.find_by_order(0));
            st.erase(st.find_by_order(0));
        }
        for(int i = 0;i<ans.size();i++)
            cout<<s[ans[i]];
        cout<<endl;
    }
    return 0;
}
