#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

vector<int> st;
vector<int> lazy;
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
    st[v] += ((r-l)+1)*lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}
int n; /*+ n is global for use default values and send less parameters */
void update(int l,int r,int val,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    update(l,r,val,v<<1,sl,m);
    update(l,r,val,v<<1|1,m+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0; 
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

void print(){
    for(int i = 0;i<n;i++){
        cout<<query(i,i)<<" ";
    }
    cout<<endl;
}

signed main(){__
    int T,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int total = ((m*(m+1))/2)*2*n;

        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        st.assign(4*n,0);
        lazy.assign(4*n,0);
       
        vector<pair<int,int>> last(n+m+7);
        
        for(auto c:nums)
            last[c] = {m+1,0};
        
        for(int i = 1;i<=m;i++){
            int p,v;
            cin>>p>>v;
            p--;
            update(0,n-1,1);
            if(nums[p]!=v){
                int lst = query(p,p);
                
                int nwv = last[nums[p]].first - (m+1-i);
                int nwv2 = (m+1)-i;
                last[nums[p]].first=nwv;
                last[nums[p]].second = i;
                last[v].first +=nwv2;
                last[v].second = i;
                int nw = last[v].first-((m+1)-i);
                update(p,p,nw-lst);
            }
            /* for(auto c:last){ */
            /*     cout<<"("<<c.first<<" ,"<<c.second<<")  "; */
            /* } */
            /* cout<<endl; */
            /* print(); */
            total-=query(0,n-1);
            nums[p] = v;
        }
        cout<<total<<endl;
    }
    return 0;
}

