#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

vector<int> st;
vector<int> lazy;
vector<bool> need;
int n;

void propagate(int v,int l,int r){
    if(!need[v])return;
    st[v] = lazy[v]*((r-l)+1);
    if(l!=r){
        lazy[v<<1] = lazy[v];
        lazy[v<<1|1] = lazy[v];
        need[v<<1] = true;
        need[v<<1|1] = true;
    }
    need[v] = false;
}

void update(int l,int r,int x,int v = 1,int sl = 0,int sr= n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return ;
    if(sl>=l && sr<=r){
        lazy[v] = x;
        need[v] = true;
        propagate(v,sl,sr);
        return ;
    }
    int m = (sl+sr)>>1;
    update(l,r,x,v<<1,sl,m);
    update(l,r,x,v<<1|1,m+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}

int query(int l,int r,int v = 1,int sl= 0,int sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l ||sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

int queryS(int s,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(sl == sr){
        if(st[v]==0 || s>1)return n;
        return sl;
    }
    int m = (sl+sr)>>1;
    propagate(v<<1,sl,m);
    propagate(v<<1|1,m+1,sr);
    if(st[v<<1]>=s)return queryS(s,v<<1,sl,m);
    return queryS(s-st[v<<1],v<<1|1,m+1,sr);
}

signed main(){
    int m,k,a,b,f,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        st.assign(4*n,0);
        need.assign(4*n,0);
        lazy.assign(4*n,0);
        for(int i = 0;i<n;i++)
            update(i,i,1);
        while(m--){
            cin>>k;
            if(k==1){
                cin>>a>>f;
                int sum = a?query(0,a-1):0;
                int first = queryS(sum+1);
                int available = query(a,n-1);
                int last = queryS(sum+min(available,f));
                if(first==n)
                    cout<<"Can not put any one."<<endl;
                else{
                    cout<<first<<" "<<last<<endl;
                    update(first,last,0);
                } 
            }
            else{
                cin>>a>>b;
                cout<<((b-a)+1)-query(a,b)<<endl;
                update(a,b,1);
            }
        }   
        cout<<endl;
    }

    return 0;
}