#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000007;
vector<int> st;
vector<int> b[maxn];
int n;

void update(int pos,int x,int l = 0,int r = n-1,int v = 1){
    if(l ==r)st[v] = x;
    else {
        int mid = (l+r)>>1;
        if(pos<=mid)
            update(pos,x,l,mid,v<<1);
        else 
            update(pos,x,mid+1,r,v<<1|1);
        st[v] = __gcd(st[v<<1],st[v<<1|1]);
    }
}
int query(int l,int r ,int sl = 0,int sr = n-1,int v = 1){
    if(sl>r || sr <l ||sl >sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int mid  = (sl+sr)>>1;
    return __gcd(query(l,r,sl,mid,v<<1),query(l,r,mid+1,sr,v<<1|1));
}

bool find(int l,int r){
    int gcd = query(l,r);
    // cout<<l<<" "<<r<<" "<<gcd<<endl;
    auto less  = lower_bound(b[gcd].begin(),b[gcd].end(),l);
    if(less == b[gcd].end())return false;
    if(*less<=r)return true;
    return false;
}

bool check(int mid){
    for(int i = 0;i<n-mid+1;i++){
        if(find(i,(i+mid-1)))return true;
    }
    return false;
}

int main(){
    cin>>n;
    st.resize(4*n);
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        b[nums[i]].push_back(i);
        update(i,nums[i]);
    }
    int l = 1,r = n+1;
    while(l+1<r){
        int mid = (l+r)>>1;
        // cout<<mid<<" "<<check(mid)<<endl;
        if(check(mid))
            l = mid;
        else r = mid;
    }
    vector<int> ans;
    for(int i = 0;i<n-l+1;i++){
        if(find(i,(i+l)-1))ans.push_back(i+1);
    }
    cout<<ans.size()<<" "<<l-1<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}