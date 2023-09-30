#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,k;
    cin>>t;
    while(t--){
        string n;
        cin>>n>>k;
        while(1){
            set<char> st;
            for(int i = 0;i<n.size();i++){
                st.insert(n[i]);
            }
            if(st.size()<=k)
                break;
            st.clear();
            int idx = 0;
            for(int i = 0;i<n.size();i++){
                st.insert(n[i]);
                if(st.size()>k)
                    break;
                idx++;
            }
            while(idx>=0 && n[idx]== '9'){
                n[idx] = '0';
                idx--;
            }
            n[idx]++;
            for(int i = idx+1;i<n.size();i++)
                n[i] = '0';
        }
        cout<<n<<endl;
    }
    return 0;
}  
