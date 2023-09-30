#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef vector<int> :: iterator it;
struct wavelet{
    vector<vector<int>> mapleft;
    int mx;
    wavelet(vector<int> &v,int mx):mapleft(mx*2),mx(mx){
        build(v.begin(),v.end(),0,mx,1);
    }

    void build(it s,it e,int l,int r,int v){
        if(l==r)return;
        int m = (l+r)>>1;
        auto f= [&](int x){
            return x<=m;
        };
        mapleft[v].reserve(e-s+1);
        mapleft[v].push_back(0);
        for(it i = s;i!=e;i++)
            mapleft[v].push_back(mapleft[v].back()+ f(*i));
        
        it p = stable_partition(s,e,f);
        build(s,p,l,m,v<<1);
        build(p,e,m+1,r,v<<1|1);
    }
    int l,r;
    int range(int i,int j,int a,int b){
        if(b<a || j<i)return 0;
        l = a,r = b;
        return range(i,j+1,0,mx,1);
    }
    int range(int i,int j,int a,int b,int v){
        if(b<l || a>r)return 0;
        if(a>=l && b<=r)return j-i;
        int m = (a+b)>>1;
        int li = mapleft[v][i],lj = mapleft[v][j];
        return range(li,lj,a,m,v<<1)+range(i-li,j-lj,m+1,b,v<<1|1);
    }
};

int main(){__
    int n,m,q,L,R,A,B;
    cin>>n>>m>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    wavelet wt(nums,m+1);
    int ans = 0;
    for(int i = 0;i<q;i++){
        cin>>L>>R>>A>>B;
        int l,r,a,b;
        (l = (L+ans)%n)++;
        (r = (R+ans)%n)++;
        (a = (A+ans)%m)++;
        (b = (B+ans)%m)++;
        if(l>r)swap(l,r);
        if(a>b)swap(a,b);
        l--,r--;
        ans = wt.range(l,r,a,b);
        cout<<ans<<endl;
    }     
}