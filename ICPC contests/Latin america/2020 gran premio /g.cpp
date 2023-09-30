#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> st; 

int N;
void update(int idx ,int x ,int v = 1,int sl = 0,int sr = N-1){
    if(sl ==sr)st[v] = x;
    else {
        int m = (sl+sr)>>1;
        if(idx<=m)update(idx,x,v<<1,sl,m);
        else update(idx,x,v<<1|1,m+1,sr);
        st[v] = max(st[v<<1],st[v<<1|1]);
    }
}

int query(int l,int r,int v = 1,int sl = 0,int sr = N-1){
    if(sl>r || sr<l ||sl>sr)return 0;
    if(sl>=l&& sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return max(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

struct q{
    int x,l,r;
};

signed main(){__
    int T = 1,n,g,a,b;
    cin>>n;
    N = n+1;
    st.resize(4*(n+1));
    vector<int> dp(n);
    vector<q> Q(n);
    for(int i = 0;i<n;i++){
        cin>>g>>a>>b;
        Q[i] = {g,min(i+a,n),min(n,i+b)};
    }

    for(int i = n-1;i>=0;i--){
        dp[i] = Q[i].x+query(Q[i].l,Q[i].r);
        update(i,dp[i]);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}