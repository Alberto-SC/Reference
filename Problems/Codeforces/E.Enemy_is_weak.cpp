#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

vector<int> st;

int N;
void update(int idx,int x,int v = 1,int sl = 0,int  sr = N-1){
    if(sl ==sr)st[v] = x;
    else{
        int m = (sl+sr)>>1;
        if(idx<=m)
            update(idx,x,v<<1,sl,m);
        else   
            update(idx,x,v<<1|1,m+1,sr);
        st[v] = st[v<<1]+st[v<<1|1];
    }
}

int query(int l,int r,int v = 1,int sl =0,int sr = N-1){
    if(sl>r ||sr<l ||sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

int main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> copy = nums;
    sort(copy.begin(),copy.end());
    vector<int> u;
    int last = copy[0];
    u.push_back(last);
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            u.push_back(last);
        }
    }
    for(int i = 0;i<n;i++)
        nums[i] = lower_bound(u.begin(),u.end(),nums[i])-u.begin();
    N = u.size();
    st.resize(4*N);
    vector<lli> left(n);
    update(nums[0],1);
    for(int i = 0;i<n;i++){
        left[i] = query(nums[i]+1,N-1);
        update(nums[i],1);
    }
    vector<lli> right(n);
    st.assign(4*N,0);
    update(nums[n-1],1);
    for(int i = n-1;i>=0;i--){
        right[i] = query(0,nums[i]-1);
        update(nums[i],1);
    }
    lli ans = 0;
    for(int i = 0;i<n;i++)
        ans+= right[i]*left[i];
    cout<<ans<<endl;
    return 0;
}