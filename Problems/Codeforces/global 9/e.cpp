#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> st;
int n;
void update(int pos ,int val,int v = 1,int sl = 0,int sr = n-1){
    if(sl ==sr)st[v] = {val,pos};
    else{

        int m = (sl+sr)>>1;
        if(pos<=m)
            update(pos,val,v<<1,sl,m);
        else
            update(pos,val,v<<1|1,m+1,sr);   
        st[v] = min(st[v<<1],st[v<<1|1]);
    }
}

pair<int,int> query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(r<sl || l>sr || sl>sr)return {1e9+7,0};
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return min(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

int main(){ 
    cin>>n;
    st.resize(4*n);
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++)
        update(i,nums[i]);
    vector<int> copy = nums;
    sort(copy.begin(),copy.end()); 
    vector<pair<int,int>> ans;
    for(int i = 0;i<n-1;i++){
        if(query(i,i).first==copy[i])continue;
        else{
            auto x = query(i+1,n-1);
            int ni = query(i,i).first;            
            ans.push_back({i+1,x.second+1});
            update(x.second,ni);
        }
        for(int k= 0;k<n;k++){
            cout<<query(k,k).first<<" ";
        }
        cout<<endl;  
    }
    
    cout<<ans.size()<<endl;
    for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
    return 0;
}