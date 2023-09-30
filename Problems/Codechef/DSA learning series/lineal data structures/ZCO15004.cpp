#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100000;
signed main(){__
	int t= 1,n,x,y;
    cin>>n;
    vector<int> xs[maxn];
    vector<int> v(maxn);
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        xs[x].push_back(y);
    }
    for(int i = 0;i<maxn;i++){
        sort(xs[i].begin(),xs[i].end());
        if(xs[i].size()==0)
            xs[i].push_back(500);
        v[i] = xs[i][0];
    }
    stack<pair<int,int>> st;
    vector<int> fr(maxn,maxn);
    vector<int> fl(maxn,-1);
    for(int i = 0;i<maxn;i++){
        while(!st.empty() && st.top().first>v[i]){
            auto top = st.top();
            fr[top.second] = i;
            st.pop();
        }
        st.push({v[i],i});
    }
    while(!st.empty())st.pop();
    for(int i = maxn;i>=0;i--){
        while(!st.empty() && st.top().first>v[i]){
            auto top = st.top();
            fl[top.second] = i;
            st.pop();
        }
        st.push({v[i],i});
    }
    int ans = 0;
    for(int i = 0;i<maxn;i++){
        ans = max(ans,v[i]*(fr[i]-fl[i]));
    }
    cout<<ans<<endl;
    return 0;
}  
