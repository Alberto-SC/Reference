#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);


struct subsequence{
    int zz,zo,oz,oo;
    friend ostream& operator <<(ostream &out ,const subsequence A){
        out<<A.zz<<" "<<A.zo<<" "<<A.oz<<" "<<A.oo<<endl;
        return out;
    }

};
vector<subsequence> st;
vector<int> lazy;

int n;
subsequence zero;


void propagate(int v,int l,int r){
    if(lazy[v]== 0)return;
    swap(st[v].zz,st[v].oo);
    swap(st[v].zo,st[v].oz);
    if(l != r){
        lazy[v<<1]^=lazy[v];
        lazy[v<<1|1]^=lazy[v];
    }
    lazy[v] = 0;
}

subsequence v4= {1,0,0,0};
subsequence v7= {0,0,0,1};

subsequence merge(subsequence A,subsequence B){
    subsequence res;
    res.zz = A.zz+B.zz;
    res.oo = A.oo+B.oo;
    res.zo = max({A.zz+B.zo,A.zz+B.oo,A.zo+B.oo});
    res.oz = max({A.oo+B.oz,A.oo+B.zz,A.oz+B.zz});
    return res;
}

void update(int l,int r,int x,bool set,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(sl>r || sr<l || sl>sr)return ;
    if(sl>=l && sr<=r){
        if(set)
            st[v] = x?v7:v4;
        else{
            lazy[v]^=x;
            propagate(v,sl,sr);
        }
        return ;
    }
    int mid = (sl+sr)>>1;
    update(l,r,x,set,v<<1,sl,mid);
    update(l,r,x,set,v<<1|1,mid+1,sr);
    st[v] = merge(st[v<<1],st[v<<1|1]);
}


int main(){__
    int q,l,r;
    char x;
    cin>>n>>q;
    st.resize(4*n);
    lazy.resize(4*n);
    for(int i = 0;i<n;i++){
        cin>>x;
        update(i,i,x=='4'?0:1,1);
    }
    string op;
    for(int i = 0;i<q;i++){
        cin>>op;
        if(op == "count"){
            cout<<max({st[1].zz,st[1].zo,st[1].oo})<<endl;
        }
        else{
            cin>>l>>r;
            l--,r--;
            update(l,r,1,0);
        }
    }

    return 0;
}