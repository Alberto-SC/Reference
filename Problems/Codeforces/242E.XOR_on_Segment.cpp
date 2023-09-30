#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;
vector<int> st[20];
vector<int> lazy[20];

int n;
void propagate(int v,int l,int r,int who){
    if(lazy[who][v]==0)return ;
    st[who][v] = ((r-l)+1)-st[who][v];
    if(l!= r){
        lazy[who][v<<1] ^= lazy[who][v];
        lazy[who][v<<1|1] ^= lazy[who][v];
    }
    lazy[who][v] = 0;
}
void update(int l,int r,int x,int who,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr,who);
    if(sl>r || sr<l ||sl>sr)return ;
    if(sl>=l && sr<=r){
        lazy[who][v]^=x;
        propagate(v,sl,sr,who);
        return ;
    }
    int m = (sl+sr)>>1;
    update(l,r,x,who,v<<1,sl,m);
    update(l,r,x,who,v<<1|1,m+1,sr);
    st[who][v] = st[who][v<<1]+st[who][v<<1|1];
}

int query(int l,int r,int who,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr,who);
    if(sl>r || sr<l ||sl>sr)return 0;
    if(sl>=l && sr<=r)return st[who][v];
    int m = (sl+sr)>>1;
    return query(l,r,who,v<<1,sl,m)+query(l,r,who,v<<1|1,m+1,sr);
}
void print(){
    for(int i = 5;i>=0;i--){
        for(int j = 0;j<n;j++){
            cout<<query(j,j,i)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int m,t,l,r,x;
    cin>>n;
    for(int i = 0;i<20;i++)
        st[i].resize(4*n),lazy[i].resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<20;j++){
            if((nums[i]>>j)&1)
                update(i,i,1,j);
        }
    }
    // print();
    cin>>m;
    for(int i = 0;i<m;i++){
        cin>>t;
        if(t == 1){
            cin>>l>>r;
            lli ans = 0;
            l--,r--;
            for(int j = 0;j<20;j++)
                ans+= query(l,r,j)*(1ll<<j);
            cout<<ans<<endl;
        }
        else{
            cin>>l>>r>>x;
            l--,r--;
            for(int j = 0;j<20;j++)
                if((x>>j) &1)
                    update(l,r,1,j);
            // print();
        }
    }
    return 0;
}