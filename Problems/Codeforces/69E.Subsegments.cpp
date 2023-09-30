#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second

vector<pair<int,int>> st;

int N;
const int inf = -(1e9+7);
void update(int pos ,int val,int v = 1,int l = 0,int r = N-1){
    if(l==r)st[v].x+=val,st[v].y= pos;
    else{
        int m = (l+r)>>1;
        if(pos<=m)
            update(pos,val,v<<1,l,m);
        else 
            update(pos,val,v<<1|1,m+1,r);
        int mxl,mxr;
        if(l == m){
            if(st[v<<1].x == 1)mxl = st[v<<1].y;
            else mxl = inf;
        }
        else  
            mxl = st[v<<1].y;
        if(m+1 == r){
            if(st[v<<1|1].x == 1)mxr = st[v<<1|1].y;
            else mxr = inf;
        }
        else 
            mxr = st[v<<1|1].y;
        // cout<<l<<" "<<r<<" "<<mxl<<" "<<mxr<<endl;
        st[v].y =max(mxl,mxr);
        st[v].x = 1;
    }
}


int query(int l,int r,int v = 1,int sl= 0,int sr = N-1){
    if(sl>r || sr<l || sl>sr)return inf;
    if(sl>=l && sr<=r)return st[v].y;
    int m = (sl+sr)>>1;
    return max(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}
void print(){
    for(int i = 0;i<N;i++){
        cout<<query(i,i)<<" ";
    }
    cout<<endl;
}
int main(){
	int t= 1,n,k;
    cin>>n>>k;
    st.resize(4*n,{0,inf});
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> copy = nums;
    vector<int> uniques;
    sort(copy.begin(),copy.end());
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    N = uniques.size();

    for(int i = 0;i<n;i++)
        nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();

    for(int i = 0;i<k;i++)
        update(nums[i],1);
    for(int i = 0;i<=n-k;i++){
        int x =query(0,N-1);
        x==inf?cout<<"Nothing"<<endl:cout<<uniques[x]<<endl;
        if(i+k<n){
            update(nums[i],-1);
            update(nums[i+k],1);
        }      
    }   

}  

