#include <bits/stdc++.h>
using namespace std;

vector<int> st;

int N;
void update(int pos ,int x,int v = 1,int l = 0,int r = N-1){
    if(l == r)st[v] = max(st[v],x);
    else{
        int mid = (l+r)>>1;
        if(pos<=mid)
            update(pos,x,v<<1,l,mid);
        else 
            update(pos,x,v<<1|1,mid+1,r);
        st[v] =max(st[v<<1],st[v<<1|1]);
    }
}
int query(int l,int r,int v = 1,int sl = 0,int sr = N-1){
    if(sl>r || sr<l || sl>sr)return 0;  
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return max(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

int main(){
    int n;
    cin>>n;
    st.resize(4*n);
    vector<int> nums(n);
    vector<int> copy(n);
    vector<int> ans(n);
    for(auto &c:nums)cin>>c;
    copy = nums;
    sort(copy.begin(),copy.end());
    vector<int> uniques;
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 1;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    N = uniques.size()+1;
    for(int i = 0;i<n;i++)
        nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin()+1;


    for(int i = n-1;i>=0;i--){
        ans[i] = query(0,nums[i]-1);
        if(ans[i]== 0)ans[i] = -1;
        else ans[i] = (ans[i]-i)-1;
        update(nums[i],i);
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}