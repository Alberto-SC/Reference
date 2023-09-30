#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int>::iterator it;

struct wavelet{
    vector<vector<int>> mapLeft;
    int mx;
    wavelet(vector<int> A,int mx):mapLeft(2*mx),mx(mx){
        build(A.begin(),A.end(),0,mx-1,1);
    }

    void build(it s,it e,int l,int r ,int v){
        if(l == r)return ;
        int m = (l+r)>>1;
        auto f = [m](int x){
            return x<=m;
        };
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        for(it i = s;i !=e;i++)
            mapLeft[v].push_back(mapLeft[v].back()+ (*i<=m));
        auto p = stable_partition(s,e,f);
        build(s,p,l,m,v<<1);
        build(p,e,m+1,r,v<<1|1);
    }

    int range(int i,int j,int a,int b){
        if(j<i || b<a)return 0;
        return range(i,j+1,0,mx-1,a,b,1);
    }
    int range(int i,int j,int l,int r,int a,int b,int v){
        if(l>b || r<a)return 0;
        if(l>=a && r<=b)return j-i;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        int mid = (l+r)>>1;
        return range(li,lj,l,mid,a,b,v<<1)+range(i-li,j-lj,mid+1,r,a,b,v<<1|1);
    }
};


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> copy(n);
    vector<int> uniquess(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        copy[i] = nums[i];
    }
    sort(copy.begin(),copy.end());
    int last = copy[0];
    uniquess.push_back(last);
    for(int i =0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniquess.push_back(last);
        }
    }
    for(int i = 0;i<n;i++)
        nums[i] = lower_bound(uniquess.begin(),uniquess.end(),nums[i])-uniquess.begin();
    
    wavelet wt(nums,uniquess.size());
    lli ans = 0;
    for(int i = 1;i<n-1;i++){
        lli l = wt.range(0,i-1,nums[i]+1,uniquess.size());
        lli r = wt.range(i+1,n-1,0,nums[i]-1);
        // cout<<l<<" "<<r<<endl;
        ans += l*r;
    }
    cout<<ans<<endl;
    return 0;
}