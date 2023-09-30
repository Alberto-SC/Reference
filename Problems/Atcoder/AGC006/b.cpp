#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int n,x;
    cin>>n>>x;
    int mx = n*2-1;
    if(x == 1 || x == mx)return cout<<"No"<<endl,0;
    int idx = mx/2;
    vector<int> ans(mx,-1);
    ans[idx] = x;
    set<int> st;
    for(int i = 1;i<=mx;i++)
        st.insert(i);
    st.erase(x);
    if(x==2){
        st.erase(1);
        st.erase(mx);
        st.erase(mx-1);
        ans[idx-1] = 1;
        ans[idx+1] = mx;
        if(n>2)
        ans[idx-2] = mx-1;
    }
    else{
        st.erase(x-1);
        st.erase(x-2);
        st.erase(mx);
        ans[idx-1] = mx;
        ans[idx-2] = x-2;
        ans[idx+1] = x-1; 
    }
    for(int i = 0;i<mx;i++){
        if(ans[i]==-1){
            ans[i] =*st.begin();
            st.erase(st.begin());
        }
    }
    cout<<"Yes"<<endl;
    for(auto c:ans)cout<<c<<endl;
    cout<<endl;

}