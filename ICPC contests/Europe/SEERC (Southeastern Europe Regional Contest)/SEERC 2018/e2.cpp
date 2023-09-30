#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

struct Node{
    int sum,greater,l,r,lazy;
    bool prop;
    vector<Node> sons;
    Node(int _l,int _r):l(_l),r(_r),lazy(0),greater(0),sum(0),prop(false){}
    void propagate(){
        if(sons.empty() && l!=r){
            int m = (l+r)>>1;
            sons.push_back(Node(l,m));
            sons.push_back(Node(m+1,r));
        }
        if(prop){
            sum += lazy*((r-l)+1);
            if(l!=r){
                sons[0].prop = true;
                sons[1].prop = true;
                sons[1].lazy += lazy;
                sons[0].lazy += lazy;
            }
            prop = false;
            lazy = 0;
        }
    }

    void update(int a,int b ,int v){
        propagate();
        if(a>r || b<l)return ;
        if(l>=a && r<=b){
            lazy += v;
            prop = true;
            propagate();
            return;
        }
        int m = (l+r)>>1;
        sons[0].update(a,b,v);
        sons[1].update(a,b,v);
        sum = sons[0].sum+sons[1].sum;
        greater=max(sons[0].greater,sons[0].sum+sons[1].greater);
    }
    int query(int k){
        propagate();
        if(l == r){return sum;}
        int m = (l+r)>>1;

        if(k<=m)
            return sons[0].query(k);
        else 
            return sons[1].query(k);
    }

};

signed main(){__
    int t,n,m,l,x,y;
    cin>>n>>m>>l;
    Node st(0,1e9+1);
    int MX = 1e9;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        int z = l-y;
        if(z<0)continue;
        st.update(max(x-z,0),min(x+z,MX),1); 
    }
    
    for(int i = 0;i<m;i++){
        cin>>x;
        cout<<st.query(x)<<endl;
    }
}   