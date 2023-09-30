#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
vector<int> nums;

vector<int> st;
vector<int> lazy1;
vector<int> lazy2;
vector<bool> changes;

int n;
void build(int v = 1,int sl = 0,int sr = n-1){
    if(sl==sr)st[v] = nums[sl];
    else {
        int m = (sl+sr)>>1;
        build(v<<1,sl,m);
        build(v<<1|1,m+1,sr);
        st[v] = st[v<<1]+st[v<<1|1];
    }
}

void propagate(int v,int l,int r){
    if(!changes[v])return ;
    int s = (r-l)+1;
    st[v]+= s*lazy1[v];
    st[v]+= ((s*(s+1))/2)*lazy2[v];
    cout<<" "<<l<<" "<<r<<" "<<lazy2[v]<<" "<<lazy1[v]<<endl;
    if(l!=r){
        int m = (l+r)>>1;
        lazy1[v<<1] +=lazy1[v];
        lazy1[v<<1|1] +=lazy1[v]+(((m+1)-l)*lazy2[v]);
        lazy2[v<<1] +=lazy2[v];
        lazy2[v<<1|1]+=lazy2[v];
        changes[v<<1] = true;
        changes[v<<1|1] = true;
    }
    lazy2[v] = 0;
    lazy1[v] = 0;
    changes[v]= false;
}

void update(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    // propagate(v,sl,sr);
    if(sl>r||sr<l ||sl>sr)return ;
    if(sl>=l && sr<=r){
        lazy1[v]+=sl-l;
        lazy2[v]++;
        changes[v] = true;
        // propagate(v,sl,sr);
        return ;
    }
    int m = (sl+sr)>>1;
    update(l,r,v<<1,sl,m);
    update(l,r,v<<1|1,m+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(sl>r||sr<l ||sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

void print(){
    for(int i = 0;i<n;i++)
        cout<<query(i,i)<<" ";
    cout<<endl;
}

signed main(){__
    int t,l,r,q;
    cin>>n>>q;
    nums.resize(n);
    st.resize(4*n);
    lazy1.resize(4*n);
    lazy2.resize(4*n);
    changes.resize(4*n);

    for(auto &c:nums)cin>>c;
    build();
    for(int i = 0;i<q;i++){
        cin>>t>>l>>r;
        l--,r--;
        if(t == 1)  
            update(l,r);
        else
            cout<<query(l,r)<<endl;
    }
    return 0;
}