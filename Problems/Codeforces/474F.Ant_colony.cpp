#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<int> st;
typedef vector<int>::iterator it;
int n;
void update(int pos ,int x ,int v = 1,int l = 0,int r =n-1){
    if(l == r)st[v] = x;
    else {
        int mid =(l+r)>>1;
        if(pos<=mid)
            update(pos,x,v<<1,l,mid);
        else
            update(pos,x,v<<1|1,mid+1,r);
        st[v]= __gcd(st[v<<1],st[v<<1|1]);
    }
} 

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(l>sr || r<sl || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int mid = (sl+sr)>>1;
    return __gcd(query(l,r,v<<1,sl,mid),query(l,r,v<<1|1,mid+1,sr));
}

struct wavelet{
    vector<vector<int>> mapLeft;
    int mx;
    wavelet(vector<int> &A ,int mx):mapLeft(2*mx),mx(mx){
        build(A.begin(),A.end(),1,0,mx-1);
    }
    void build(it s,it e,int v,int l,int r){
        if(l == r)return ;
        int mid = (l+r)>>1;
        auto f= [mid](int x){
            return x<=mid;
        };
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        for(it i = s;i!=e;i++)
            mapLeft[v].push_back(mapLeft[v].back()+ (*i<=mid));

        it p= stable_partition(s,e,f);
        build(s,p,v<<1,l,mid);
        build(p,e,v<<1|1,mid+1,r);
    }

    int rank(int i,int k){
        i++;
        int wl = 0,wr = mx-1,left;
        int u = 1;
        while(wl< wr){
            int mid = (wl+wr)>>1;
            left = mapLeft[u][i];
            u<<=1;
            if(k<=mid)
                i = left,wr = mid;
            else 
                i-=left,wl = mid+1,u|=1;
        }
        return i;
    }
};

int main(){__
    int l,r,q;
    cin>>n;
    st.resize(4*n);
    vector<int> nums(n);
    vector<int> copy(n);
    vector<int> uniques;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        copy[i] = nums[i];
    }
    sort(copy.begin(),copy.end());
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 1;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }   
    for(int i = 0;i<n;i++){
        update(i,nums[i]);
        nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
    }
    cin>>q;
    wavelet wt(nums,uniques.size());
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        int gcd = query(l,r);
        int idx = lower_bound(uniques.begin(),uniques.end(),gcd)-uniques.begin();
        // cout<<gcd<<" "<<uniques[idx]<<" "<<wt.rank(r,idx)<<" "<<wt.rank(l-1,idx)<<endl;
        if(uniques[idx]!= gcd)cout<<(r-l)+1<<endl;
        else 
            cout<<((r-l)+1)-(wt.rank(r,idx)-wt.rank(l-1,idx))<<endl;
    }
    return 0;
}