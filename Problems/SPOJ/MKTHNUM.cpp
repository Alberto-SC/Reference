#include <bits/stdc++.h>
using namespace std;
typedef vector<int>::iterator it;
#define endl "\n"
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
struct wavelet{
    vector<vector<int>> mapLeft;
    int mx;
    wavelet(vector<int> &A,int mx):mapLeft(mx*2),mx(mx){
        build(A.begin(),A.end(),0,mx-1,1);
    }
    void build(it s,it e,int l,int r,int v){
        if(l== r)return;
        int m = (l+r)>>1;
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        auto f = [m](int x){
            return x<=m;
        };
        for(it iter = s; iter!= e;iter++)
            mapLeft[v].push_back(mapLeft[v].back() + (*iter<=m));
        it p = stable_partition(s,e,f);
        build(s,p,l,m,v<<1);
        build(p,e,m+1,r,v<<1|1);
    }
    int kth(int i,int j,int k){
        j++;
        int l = 0,r = mx-1,u = 1,li,lj;
        while(l!=r){
            int m = (l+r)>>1;
            li = mapLeft[u][i],lj = mapLeft[u][j];
            u<<=1;
            if(k<= lj-li)
                i = li,j = lj, r = m;
            else 
                i-=li,j-=lj,l = m+1,u|=1,k-=(lj-li);
        }
        return r;
    }
};

int main(){__
    int n,q,l,r,k;
    cin>>n>>q;
    vector<int> nums(n);
    vector<int> copy(n);
    vector<int> uniques;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        copy[i] = nums[i];
    }
    sort(copy.begin(),copy.end());
    int last =copy[0];
    uniques.push_back(copy[0]);
    for(int i = 0;i<n;i++)
        if(copy[i]!=last)uniques.push_back(copy[i]),last = copy[i];
    
    for(int i = 0;i<n;i++)
        nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
    wavelet wt(nums,uniques.size());
    for(int i = 0;i<q;i++){
        cin>>l>>r>>k;
        l--,r--;
        cout<<uniques[wt.kth(l,r,k)]<<endl;
    }
    return 0;

}