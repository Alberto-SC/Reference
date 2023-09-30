#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef vector<int>::iterator it;
 
vector<int> L;
vector<int> R;
vector<vector<int>> mapLeft,sumLeft;
int newNode(){
  mapLeft.push_back({});
  L.push_back(0);
  R.push_back(0);
  return mapLeft.size()-1;
}
 
int mn, mx;
int wavelet(it s,it e,int l,int r){
    int m = (l+r)>>1;
    int v = newNode();
    mapLeft[v].reserve(e-s+1);
    mapLeft[v].push_back(0);
    auto f = [m](int x){
        return x<=m;
    };
    for(it iter = s; iter!= e;iter++){
        mapLeft[v].push_back(mapLeft[v].back() + (*iter<=m));
    }
    it p = stable_partition(s,e,f);
    if(l== r)return v;
    L[v] =  wavelet(s,p,l,m);
    R[v] =  wavelet(p,e,m+1,r);
    return v;
}


int range(int i, int j,int a,int b,int v= 0,int wl = 0,int wr = mx){
    if(wr<a || wl>b)return 0;
    if(wl>=a && wr<=b)return j-i;
    int m = (wl+wr)>>1;
    int li = mapLeft[v][i],lj = mapLeft[v][j];
    return range(li,lj,a,b,L[v],wl,m)+range(i-li,j-lj,a,b,R[v],m+1,wr);
}


signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c,c--;
        vector<int> v = nums;
        mx = v.size()-1;
        L.clear();
        R.clear();
        mapLeft.clear();
        wavelet (v.begin(),v.end(),0,mx);
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int x = nums[i]; //b
                int y = nums[j]; //c
                int left = range(0,i,0,y-1);
                int right  = range(j+1,n,0,x-1);
                ans +=left*right;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}