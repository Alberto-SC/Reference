#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> st[2];
vector<int> lazy[2];
int n;
void propagate(int v,int l ,int r,int who){
    if(!lazy[who][v])return ;
    st[who][v] = ((r-l)+1)*lazy[who][v];
    if(l!= r){
        lazy[who][v<<1] = lazy[who][v];
        lazy[who][v<<1|1] = lazy[who][v];
    }
    lazy[who][v] = 0;
}

void update(int l,int r,int val,int who,int v = 1,int sl = 0,int sr = n){
    propagate(v,sl,sr,who);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[who][v] = val;
        propagate(v,sl,sr,who);
        return;
    }
    int m = (sl+sr)>>1;
    update(l,r,val,who,v<<1,sl,m);
    update(l,r,val,who,v<<1|1,m+1,sr);
    st[who][v] = st[who][v<<1]+st[who][v<<1|1];
}

int query(int l,int r,int who,int v = 1,int sl = 0,int sr = n){
    propagate(v,sl,sr,who);
    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[who][v];
    int m = (sl+sr)>>1;
    return query(l,r,who,v<<1,sl,m)+query(l,r,who,v<<1|1,m+1,sr);
}
void print(int n){
    for(int i = 1;i<=n;i++)
        cout<<query(i,i,0)<<" ";
    cout<<endl;
    for(int i = 1;i<=n;i++)
        cout<<query(i,i,1)<<" ";
    cout<<endl;
}
signed main(){__
	int t= 1,x,k;
    cin>>n>>t;
    st[0].resize(4*(n+1));
    st[1].resize(4*(n+1));
    lazy[0].resize(4*(n+1));
    lazy[1].resize(4*(n+1)); 
    for(int i = 0;i<=n;i++)
        update(i,i,0,0),update(i,i,n+1,1);
    while(t--){ 
        cin>>k;
        int l = query(k,k,0),r = query(k,k,1);
        cout<<l<<" "<<r<<endl;
        while(l+1<r){
            int m = (l+r)>>1;
            cout<<"? "<<1<<" "<<m<<endl;
            cin>>x;
            if(m-x>=k)
                r = m;
            else
                l = m;
        }
        cout<<"! "<<r<<endl;
        update(1,k-1,r,1);
        update(k,n,r,0);
        print(n);
    }
    return 0;
}  
