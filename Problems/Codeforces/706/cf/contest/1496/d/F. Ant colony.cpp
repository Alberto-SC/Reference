#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int n;
vector<int> st;
void update(int pos ,int x ,int v = 1,int l = 0,int r =n-1){
    if(l == r)st[v] = x;
    else {
        int mid =(l+r)>>1;
        if(pos<=mid)
            update(pos,x,v<<1,l,mid);
        else
            update(pos,x,v<<1|1,mid+1,r);
        st[v]= __gcd(st[v<<1],st[v<<1|1]);
    }
} 

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(l>sr || r<sl || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int mid = (sl+sr)>>1;
    return __gcd(query(l,r,v<<1,sl,mid),query(l,r,v<<1|1,mid+1,sr));
}


vector<map<int,int>> st2;

vector<int> nums;
void build(int v= 1,int l = 0,int r = n-1){
    if(l ==r){
        st2[v][nums[l]]++;
    }
    else{
        int m = (l+r)>>1;
        build(v<<1,l,m);
        build(v<<1|1,m+1,r);
        st2[v] = st2[v<<1];
        for(auto c:st2[v<<1|1])st2[v][c.first]+=c.second;
    }
}

int query2(int l,int r,int x,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>=l && sr<=r){
        if(st2[v].count(x))
            return st2[v][x];
        else 
            return 0;
    }
    int m = (sl+sr)>>1;
    return query2(l,r,x,v<<1,sl,m)+query2(l,r,x,v<<1|1,m+1,sr);
}

int main(){__
    int q,l,r;
    cin>>n;
    st.resize(4*n);
    st2.resize(4*n);
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++)
        update(i,nums[i]);
    build();
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        int gcd = query(l,r);
        int cont= query2(l,r,gcd);
        cout<<((r-l)+1)-cont<<endl;
    }
    return 0;    
}