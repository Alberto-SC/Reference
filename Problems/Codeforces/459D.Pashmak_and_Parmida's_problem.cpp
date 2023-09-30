#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef vector<int>::iterator it;
typedef long long int lli;
struct wavelet {
    vector<vector<int>> mapLeft;
    int mx;
    wavelet(vector<int> &A,int mx):mapLeft(2*mx),mx(mx){
        build(A.begin(),A.end(),0,mx-1,1);
    }

    void build(it s,it e,int l,int r,int v){
        if(l == r)return ;
        int mid = (l+r)>>1;
        auto f = [mid](int x){
            return x<=mid;
        };
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        for(it i = s;i!= e;i++)
            mapLeft[v].push_back(mapLeft[v].back()+ (*i<=mid));
        it p = stable_partition(s,e,f);
        build(s,p,l,mid,v<<1);
        build(p,e,mid+1,r,v<<1|1);
    }
    int l,r;
    int range(int i,int j,int a,int b){
        if(b<a || j<i)return 0;
        l = a,r = b;
        return range(i,j+1,0,mx-1,1);
    }
    int range(int i,int j ,int a,int b,int v){
        if(b<l || a>r)return 0;
        if(a>=l && b<=r)return j-i;
        int m = (a+b)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        return range(li,lj,a,m,v<<1)+range(i-li,j-lj,m+1,b,v<<1|1);
    }
};
int main(){__
    int n;
    cin>>n;
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
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    for(int i = 0;i<n;i++)
        nums[i]= lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
    vector<int> L(n);
    vector<int> R(n);
    vector<int> buck(uniques.size());
    for(int i = 0;i<n;i++){
        buck[nums[i]]++;
        L[i] = buck[nums[i]];
    }
    buck.assign(uniques.size(),0);
    for(int i = n-1;i>=0;i--){
        buck[nums[i]]++;
        R[i] = buck[nums[i]];
    }
    wavelet wt(R,n);
    lli ans = 0;
    for(int i = 0;i<n;i++){
        ans += wt.range(i+1,n-1,0,L[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}