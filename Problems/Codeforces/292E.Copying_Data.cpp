#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int> st;
vector<int> lazy;

void propagate(int v,int l,int r){
    if(lazy[v] == 0)return;
    st[v] =lazy[v];
    if(l != r){ 
        lazy[v<<1] = lazy[v];
        lazy[v<<1|1] = lazy[v];
    }
    lazy[v]  = 0;
}

int n;
void update(int l,int r,int x,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(l> sr || r <sl || sl >sr)return ;
    if(sl>=l && sr<=r){
        lazy[v] = x;
        propagate(v,sl,sr);
        return;
    }
    int mid = (sl+sr)>>1;
    update(l,r,x,v<<1,sl,mid);
    update(l,r,x,v<<1|1,mid+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}


int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(l> sr || r<sl || sl>sr)return 0;
    if(sl>=l && sr<= r)return st[v];
    int mid = (sl+sr)>>1;
    return query(l,r,v<<1,sl,mid)+ query(l,r,v<<1|1,mid+1,sr);
}
void print(){
    for(int i = 0;i<n;i++)
        cout<<query(i,i)<<" ";
    cout<<endl;
}
int main(){__
    int q,type,x,y,k;
    cin>>n>>q;
    st.resize(4*n);
    lazy.resize(4*n);
    vector<int> b(n);
    vector<int> a(n);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    int cont = 0;
    vector<pair<int,int>>qu;
    for(int i = 0;i<q;i++){
        cin>>type;
        if(type == 1){
            cin>>x>>y>>k;
            x--,y--;
            update(y,(y+k)-1,cont+1);
            qu.push_back({x,y});
            cont++;
            // print();
        }
        else {
            cin>>x;
            x--;
            int c = query(x,x);
            if(c == 0)cout<<b[x]<<endl;
            else{
                c--;
                int off = x-qu[c].second;
                cout<<a[qu[c].first+off]<<endl;
            }
        }
    }
    return 0;
}