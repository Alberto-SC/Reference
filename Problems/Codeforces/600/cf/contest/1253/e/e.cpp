#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> st;
vector<int> lazy;
int m;

void propagate(int v,int l,int r){
    if(lazy[v]==-1)return;
    st[v] = lazy[v]*((r-l)+1);
    if(l!=r){
        lazy[v<<1] = lazy[v];   
        lazy[v<<1|1] = lazy[v];
    }
    lazy[v] = -1;
}

void update(int l,int r,int x,int v = 1,int sl = 0,int sr = m-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return;
    if(sl>=l &&sr<=r){
        lazy[v] = x;
        propagate(v,sl,sr);
        return ;
    }
    int mid = (sl+sr)>>1;
    update(l,r,x,v<<1,sl,mid);
    update(l,r,x,v<<1|1,mid+1,sr);
    st[v]= st[v<<1]+st[v<<1|1];
}

int query(int v = 1,int sl = 0,int sr = m-1){
    propagate(v,sl,sr);
    if(sl==sr)return st[v]?-1:sl;
    int mid = (sl+sr)>>1;
    int left = (mid-sl)+1;
    propagate(v<<1,sl,mid);
    propagate(v<<1|1,mid+1,sr);
    cout<<sl<<" "<<sr<<" "<<mid<<" "<<st[v<<1]<<" "<<st[v<<1|1]<<endl;
    if(st[v<<1]==left)
        return query(v<<1|1,mid+1,sr);
    else 
        return query(v<<1,sl,mid);
}


signed main(){__
	int t= 1,n,x,s;
    cin>>n>>m;
    st.resize(4*m);
    lazy.resize(4*m,-1);
    vector<pair<int,int>> a(n);
    for(int i = 0;i<n;i++){
        cin>>x>>s;
        x--;
        a[i] = {x,s};
        cout<<max(0ll,x-s)<<" "<<min(m-1,x+s)<<endl;
        update(max(0ll,x-s),min(m-1,x+s),1);
        cout<<st[1]<<endl;
    }
    cout<<st[1]<<endl;
    int ans = 0;
    while(1){
        int pos = query();
        if(pos==-1)break;
        int idx = 0,diff = 0,mx=0,d;
        for(int i = 0;i<n;i++){
            if(a[i].first>pos){
                d = (a[i].first-a[i].second)-pos;
                diff = d;
                idx = i;
                break;
            }
        }
        cout<<pos<<" "<<diff<<endl;
        if(diff==0){
            ans+=(m-pos)+1;
            break;
        }
        ans+= diff;
        a[idx].second+=diff;
        cout<<a[idx].first<<" "<<a[idx].second<<endl;
        cout<<st[1]<<endl;
        update(max(0ll,a[idx].first-a[idx].second),min(m-1,a[idx].first+a[idx].second),1);
        cout<<st[1]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}  
