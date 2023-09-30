#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
vector<ordered_set> st;
vector<int> nums;
void build(int v = 1,int sl = 0,int sr = n-1){
    if(sl ==sr)
        st[v].insert(nums[sl]);
    else{
        int m = (sl+sr)>>1;
        build(v<<1,sl,m);
        build(v<<1|1,m+1,sr);
        st[v] = st[v<<1];
        for(auto c:st[v<<1|1])st[v].insert(c);
    }
}

void update(int idx,int x,int v = 1,int sl = 0,int sr = n-1){
    if(sl== sr){
        st[v].erase(st[v].upper_bound(nums[idx]));
        st[v].insert(x);
        return ;
    }

    int m = (sl+sr)>>1;
    if(idx<=m)
        update(idx,x,v<<1,sl,m);
    else
        update(idx,x,v<<1|1,m+1,sr);
    st[v].erase(st[v].upper_bound(nums[idx]));
    st[v].insert(x);
}

int query(int l,int r,int x,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r ||sr<l ||sl>sr)return 0;
    if(sl>=l && sr<=r){
        int k = st[v].order_of_key(x);
        return st[v].size()-k;
    }
    int m = (sl+sr)>>1;
    return query(l,r,x,v<<1,sl,m)+query(l,r,x,v<<1|1,m+1,sr);
}


int main(){__
    int q,t,l,r,x,c,idx;
    cin>>n;
    nums.resize(n);
    st.resize(4*n);
    for(auto &c:nums)cin>>c; 
    build();
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>t;
        if(t ==0){
            cin>>l>>r>>c;
            l--,r--;
            cout<<query(l,r,c)<<endl;
        }
        else{
            cin>>idx>>x;
            idx--;
            update(idx,x);
            nums[idx] = x;
        }
    }
    return 0;
}