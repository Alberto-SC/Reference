#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> st;
#define endl '\n'
tuple<int,int,int> merge(tuple<int,int,int> A,tuple<int,int,int> B){
    int x = min(get<0>(A),get<1>(B));
    tuple<int,int,int> ans;
    get<2>(ans) = get<2>(A)+get<2>(B) + x;
    get<0>(ans) = get<0>(A)+get<0>(B) - x;
    get<1>(ans) = get<1>(A)+get<1>(B) - x;
    return ans; 
}
string s;
void build(int v,int l,int r){
    if(l == r)st[v] = {s[l]=='(',s[l]==')',0};
    else {
        int m = (l+r)/2;
        build(v*2,l,m);
        build(v*2+1,m+1,r);
        st[v] = merge(st[v*2],st[v*2+1]);
    }
}
tuple<int,int,int> query(int v,int SL,int SR ,int l ,int r){
    if(SL>r || SR<l)return {0,0,0};
    if(SL>= l && SR<=r )return st[v];
    int m = (SL+SR)/2;
    return merge(query(v*2,SL,m,l,r), query((v*2)+1,m+1,SR,l,r));
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n,q,l,r;
    cin>>s;
    n = s.size();
    st.resize(4*n);
    build(1,0,n-1);
    // for(int i = 0;i<4*n;i++){cout<<"("<<get<0>(st[i])<<","<<get<1>(st[i])<<","<<get<2>(st[i])<<")   ";}
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        l--;
        r--;
        tuple<int,int,int> ans;
        ans = query(1,0,n-1,l,r);
        cout<<get<2>(ans)*2<<endl;
    }
    return 0;
}