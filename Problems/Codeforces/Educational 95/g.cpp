#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int lli;

vector<ld> st;
vector<ld> lazy;

void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
    st[v] += st[v]*lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 1;
}

void update(int v,int sl,int sr,int l,int r,ld val){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        propagate(v,sl,sr);  
        return;
    }
    int m = (sl+sr)>>1;
    update(v<<1,sl,m,l,r,val);
    update(v<<1|1,m+1,sr,l,r,val);
    st[v] = st[v<<1]*st[v<<1|1];
}

ld query(int v,int sl,int sr,int l,int r){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 1;
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(v<<1,sl,m,l,r)*query(v<<1|1,m+1,sr,l,r);
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n)
    for(auto &c:nums)cin>>c;
    lli ans = 0;
    for(int i = 3;i<n;i+=3){
        st.assign(4*n,3 );
        for(int j = 0;j<i;j++)
            update(nums[j],nums[j],1.0);

        update(0,n-1,)
        
        for(int j = 0;j<n-i;j++){

        }
    }
    return 0;
}