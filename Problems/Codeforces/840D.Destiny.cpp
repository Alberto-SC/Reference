#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef vector<int>:: iterator it;
struct wavelet{
    vector<vector<int>> mapLeft;
    int mx;

    wavelet(vector<int> &A,int mx):mapLeft(2*mx) ,mx(mx){
        build(A.begin(),A.end(),0,mx-1,1);
    }

    void build(it s,it e,int l,int r,int v){
        if(l ==r)return ;
        int m = (l+r)>>1;
        auto f = [m](int x){
            return x<=m;
        };
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        for(it i = s; i!=e;i++)
            mapLeft[v].push_back(mapLeft[v].back()+ (*i<=m));
        auto p = stable_partition(s,e,f);
        build(s,p,l,m,v<<1);
        build(p,e,m+1,r,v<<1|1);
    }


    int minimun_of_ocurrences(int i,int j,int k){
        return minimun_of_ocurrences(i,j+1,k,1,0,mx-1);
    }  
    int minimun_of_ocurrences(int i,int j,int k,int v ,int l,int r ){
        // cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<k<<endl;
        if(l == r)return j-i>= k?l:mx+2;
        if(j-i<k)return mx+2;
        int m = (l+r)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        // cout<<li<<" "<<lj<<endl;
        int c = lj-li;
        // cout<<c<<endl;
        int ans= mx+2;
        if(c >=k)
            ans = min(ans,minimun_of_ocurrences(li,lj,k,v<<1,l,m));
        if((j-i)-c>=k)
            ans = min(ans,minimun_of_ocurrences(i-li,j-lj,k,v<<1|1,m+1,r));
        if(c <k && (j-i)-c<k)return mx+2;
        return ans;
    }

};



int main(){__
    int n,q,l,r,k;
    cin>>n>>q;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,c--;
    wavelet wt(nums,n);
    for(int i = 0;i<q;i++){
        cin>>l>>r>>k;
        l--,r--;
        int c = (r-l+1)/k;
        // cout<<c<<endl;
        int ans = wt.minimun_of_ocurrences(l,r,c+1);
        if(ans== n+2)cout<<-1<<endl;
        else cout<<ans+1<<endl;
    }    

    return 0;
}