#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,m,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m>>x;
        set<pair<int,int>> st;
        for(int i =1;i<=m;i++)
            st.insert({0,i});
        cout<<"YES"<<endl;
        for(int i = 0;i<n;i++){
            cin>>y;
            int mn = (*st.begin()).first;
            int who = (*st.begin()).second;
            cout<<who<<" ";
            st.erase(st.begin());
            st.insert({mn+y,who});
        }
        cout<<endl;
    }
    return 0;
}  
