#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> st(4*n);
void update(int pos,int val,int idx,int l = 0,int r = n-1,int v = 1){
    // cout<<l<<" "<<r<<" "<<pos<<" "<<((l+r)>>1)<<endl;
    if(l == r)st[v].first+=val,st[v].second = idx;
    else{
        int mid = (l+r)>>1;
        if(pos<=mid)
            update(pos,val,idx,l,mid,v<<1);
        else 
            update(pos,val,idx,mid+1,r,v<<1|1);
        st[v] = max(st[v<<1],st[v<<1|1]);
    }
}

pair<int,int> query(int l,int r,int sl = 0,int sr = n-1,int v = 1){
    if(sl>r || sr <l ||sl>sr)return {-1,-1};
    if(sl>=l && sr<=r)return st[v];
    int mid = (sl+sr)>>1;
    return max(query(l,r,sl,mid,v<<1),query(l,r,mid+1,sr,v<<1|1));
}
void print(){
    for(int i = 0;i<n;i++)
        cout<<"("<<query(i,i).first<<","<<query(i,i).second<<")  ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){ 
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        st.assign(4*n,{0,0});

        int l = -1,r = 0;
        int ans = n+1;
        n++;
        while(l<r && r<n-1){
            update(nums[r],1,nums[r]);
            // print();
            auto max1 = query(0,n-1);
            update(max1.second,-max1.first,max1.second);
            auto max2 = query(0,n-1);
            update(max1.second,max1.first,max1.second);
            // cout<<l<<" "<<r<<" "<<max1.first<<" "<<max2.second<<endl;
            while(l<r && max1.first>max2.first && (r-l)>1){
                ans = min(r-l,ans);
                ++l;
                update(nums[l],-1,nums[l]);
                max1 = query(0,n-1);
                update(max1.second,-max1.first,max1.second);
                max2 = query(0,n-1);
                update(max1.second,max1.first,max1.second);
            }
            r++;
        }
        if(ans== n)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}