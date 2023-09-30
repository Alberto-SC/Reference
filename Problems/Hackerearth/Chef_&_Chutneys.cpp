#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
const lli mod = 1e9+7;
lli bin_pow(lli a,lli b){
    lli x= 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
struct basis{
    int base[32],sz = 0;
    basis(){
        for(int i = 0;i<31;i++)
            base[i] = 0;
    }
    bool check(int x){
        while(x!= 0 && base[31-__builtin_clz(x)]!= 0){
            x^=base[31-__builtin_clz(x)];
        }
        if(!x)return true;
        else return false;
    }
    void add(int x){
        while(x!=0 && base[31-__builtin_clz(x)]!= 0){
            x^=base[31-__builtin_clz(x)];
        }
        if(!x)return;
        base[31-__builtin_clz(x)] = x;
        sz++;
    }
};
vector<basis> st;
basis mergeBasis(basis l,basis r){
    basis bs;
    for(int i = 0;i<30;i++){
        bs.add(l.base[i]);
        bs.add(r.base[i]);
    }
    return bs;
}

int n;
void update(int pos,int val,int v = 1,int l = 0,int r = n-1){
    if(l == r){
        basis nw;
        nw.add(val);
        st[v] = nw;
    }
    else {
        int m = (l+r)>>1;
        if(pos<=m)
            update(pos,val,v<<1,l,m);
        else 
            update(pos,val,v<<1|1,m+1,r);
        st[v] = mergeBasis(st[v<<1],st[v<<1|1]);
    }
}

basis zero;
basis query(int l,int r,int v =1 ,int sl = 0,int sr = n-1){
    if(sl>r || sr<l || sl>sr)return zero;
    if(sl>=l && sr<=r)return st[v];
    int mid = (sl+sr)>>1;
    return mergeBasis(query(l,r,v<<1,sl,mid),query(l,r,v<<1|1,mid+1,sr));
}
int main(){__
    int q;
    string s;
    cin>>n>>q;
    st.resize(4*n);
    for(int i = 0;i<n;i++){
        cin>>s;
        vector<int> b(26);
        for(auto c:s)
            b[c-'a']++;
        int mask = 0;
        for(int j = 0;j<26;j++)
            if(b[j]&1)mask|= (1<<j);
        update(i,mask);
    }
    for(int i = 0;i<q;i++){
        int type,l,r,pos;
        cin>>type;
        if(type == 2){
            cin>>l>>r;
            l--,r--;
            basis rangeQ = query(l,r);
            lli ans = 0;
            for(int k = 0;k<31;k++){
                if(rangeQ.check(1<<k))
                    (ans+=bin_pow(2,((r-l)+1)-rangeQ.sz))%=mod;
            }
            (ans+=bin_pow(2,((r-l)+1)-rangeQ.sz)-1)%=mod;
            if(ans<0)ans+=mod;
            cout<<ans<<endl;
        }
        else{
            cin>>pos>>s;
            pos--;
            vector<int> b(26);
            for(auto c:s){
                b[c-'a']++;
            }
            int mask = 0;
            for(int j = 0;j<26;j++)
                if(b[j]&1)mask|=(1<<j);
            update(pos,mask);
        }
    }
    return 0;
}