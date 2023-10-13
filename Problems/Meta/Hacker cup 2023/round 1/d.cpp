#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

vector<pair<pair<int,int>,pair<int,int>>> st;
vector<int> lazy;

int n;
void propagate(int v,int l,int r){
    if(lazy[v]==0)return ; 
    st[v]  = {st[v].second,st[v].first};
    if(l!= r){
        lazy[v<<1]^=1;
        lazy[v<<1|1]^=1;
    }
    lazy[v] = 0;
}


void build(vector<int> &A,int v = 1,int sl = 0,int sr = n-1){
    if(sl == sr){
        st[v] = {{A[sl],sl},{(A[sl]*(mod-1))%mod,sl}};
        return ;
    }
    int m = (sl+sr)>>1;
    build(A,v<<1,sl,m);
    build(A,v<<1|1,m+1,sr);

    if(st[v<<1|1].first.first>st[v<<1].first.first)
        st[v].first = st[v<<1|1].first;
    else 
        st[v].first = st[v<<1].first;

    if(st[v<<1|1].second.first>st[v<<1].second.first)
        st[v].second = st[v<<1|1].second;
    else 
        st[v].second = st[v<<1].second;

}

void update(int l,int r ,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return;
    if(sl>=l && sr<=r){
        lazy[v]^=1;
        propagate(v,sl,sr);
        return ;
    }
    int m =(sl+sr)>>1;
    update(l,r,v<<1,sl,m);
    update(l,r,v<<1|1,m+1,sr);
    
    if(st[v<<1|1].first.first>st[v<<1].first.first)
        st[v].first = st[v<<1|1].first;
    else 
        st[v].first = st[v<<1].first;

    if(st[v<<1|1].second.first>st[v<<1].second.first)
        st[v].second = st[v<<1|1].second;
    else 
        st[v].second = st[v<<1].second;
}

int queryLR(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v].first.first;
    int m =(sl+sr)>>1;
    return max(queryLR(l,r,v<<1,sl,m),queryLR(l,r,v<<1|1,m+1,sr));
}

void print(){
    for(int i = 0;i<n;i++){
        cout<<queryLR(i,i)<<" ";
    }
    cout<<endl;
}


signed main(){
	int T= 1,l,r,Q;
    int id = 1;
    cin>>T;
    while(T--){
        cin>>n;
        st.resize(4*n);
        lazy.assign(4*n,0);

        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        build(nums);
        
        cin>>Q;
        int ans = 0;
        for(int i = 0;i<Q;i++){
            cin>>l>>r;
            l--,r--;
            update(l,r);
            ans+=st[1].first.second+1;
        }
 
        cout<<"Case #"<<id<<": "<<ans<<endl;
        id++;
    }
    return 0;
}  

