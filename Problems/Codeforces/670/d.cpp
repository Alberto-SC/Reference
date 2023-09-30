#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> a;
vector<int> b;
vector<int> c;
int n;
vector<int> st[2];
vector<int> lazy[2];


void propagate(int v,int l ,int r,int who){
    if(!lazy[who][v])return ;
    st[who][v] += st[who][v]+lazy[who][v];
    if(l!= r){
        lazy[who][v<<1] += lazy[who][v];
        lazy[who][v<<1|1]+= lazy[who][v];
    }
    lazy[who][v] = 0;
}

void update(int v,int sl,int sr,int l,int r,lli val,int who){
    propagate(v,sl,sr,who);
    if(r<sl || l>sr || sl>sr)return;
    if(sl>= l && sr<=r){
        lazy[who][v] += val;
        propagate(v,sl,sr,who);
        return;
    }
    int m = (sl+sr)>>1;
    update(v<<1,sl,m,l,r,val,who);
    update(v<<1|1,m+1,sr,l,r,val,who);
    st[who][v] = max(st[who][v<<1],st[who][v<<1|1]);
}

lli query(int v,int sl,int sr,int l,int r,int who){
    propagate(v,sl,sr,who);

    if(r<sl || l>sr || sl>sr)return 0;
    if(sl>= l && sr<=r)return st[who][v];
    int m = (sl+sr)>>1;
    return max(query(v<<1,sl,m,l,r,who),query(v<<1|1,m+1,sr,l,r,who));
}

bool isPossible(int mid){
    b[n-1] = mid;
    c[n-1] = a[n-1]-b[n-1];
    for(int i = n-2;i>=0;i--){
        if(a[i]>=a[i+1]){
            b[i] = b[i+1];
            c[i] = a[i]-b[i];
        }
        else{
            c[i] = c[i+1];
            b[i] = a[i]-c[i];
        }
    }
    if(c[0]>mid)return false;
    else return true;
}
int main(){__
    int q,x;
    cin>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    st[0].resize(4*n);
    st[1].resize(4*n);
    lazy[0].resize(4*n);
    lazy[1].resize(4*n);
    for(auto &c:a)cin>>c;
    int l = -1000000000,r = 1000000000;
    while(l<r){
        int mid = (l+r)>>1;
        if(isPossible(mid))
            r = mid;
        else 
            l = mid+1;
    }

    vector<int> b(n);
    vector<int> c(n);
    b[n-1] = l;
    c[n-1] = a[n-1]-b[n-1];
    for(int i = n-2;i>=0;i--){
        if(a[i]>=a[i+1]){
            b[i] = b[i+1];
            c[i] = a[i]-b[i];
        }
        else{
            c[i] = c[i+1];
            b[i] = a[i]-c[i];
        }
    }
    cout<<l<<endl;
    // for(auto d:b)cout<<d<<" ";
    // cout<<endl;
    // for(auto d:c)cout<<d<<" ";
    // cout<<endl;
    cin>>q;
    for(int i = 0;i<n;i++)
        update(1,0,n-1,i,i,b[i],0);
    for(int i = 0;i<n;i++)
        update(1,0,n-1,i,i,c[i],1);
    for(int i = 0;i<q;i++){
        cin>>l>>r>>x;
        l--,r--;
        if(l){
            int diff = c[l-1]-c[l];
            update(1,0,n-1,l,r,min({x,diff}),1);
            update(1,0,n-1,l,r,x-min(x,diff),0);
        }
        else {
            update(1,0,n-1,l,r,min(x,mxinb-mxinc),1);
            update(1,0,n-1,l,r,x-min(x,mxinb-mxinc),0);
        }
        if(r<n-1){
            int mxleftb = query(1,0,n-1,r+1,n-1,0);
            int mxleftc = query(1,0,n-1,r+1,n-1,1);
        }
        cout<<min(query(1,0,n-1,0,n-1,0),query(1,0,n-1,0,n-1,1))<<endl;


    }
    return 0;
}