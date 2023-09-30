#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    vector<int> _all1;
    vector<int> _all2;
    set<int> st;
    for(int i = 0;i<=9;i++){
        for(int j = 1;j<=18;j++){
            string x(j,i+'0'); 
            st.insert(stoll(x));
        }
    }
    for(auto c:st)
        _all1.push_back(c);
    st.clear();
    for(int i = 0;i<=9;i++){
        for(int j = 0;j<=9;j++){
            for(int k = 1;k<=18;k++){
                string x(k,'0');
                for(int mask = 0;mask<(1<<k);mask++){
                    for(int z = 0;z<k;z++){
                        if((mask>>z)&1)
                            x[z] = char(i+'0');
                        else    
                            x[z] = char(j+'0');
                    }
                    st.insert(stoll(x));
                }
            }
        }
    }
    for(auto c:st)
        _all2.push_back(c);
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k ==1){
            int idx = lower_bound(_all1.begin(),_all1.end(),n)-_all1.begin();
            cout<<_all1[idx]<<endl;
        }
        else{
            int idx = lower_bound(_all2.begin(),_all2.end(),n)-_all2.begin();
            cout<<_all2[idx]<<endl;
        }
    }
    return 0;
}  
