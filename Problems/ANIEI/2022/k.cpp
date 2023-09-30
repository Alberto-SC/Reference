#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
 
vector<int> rev;

typedef vector<int>::iterator it;
struct wavelet{
    vector<vector<int>> mapLeft,sumLeft;
    int mx;
    wavelet(vector<int> &A,int mx):mapLeft(mx*2),mx(mx),sumLeft(mx*2){
        build(A.begin(),A.end(),0,mx,1);
    }
    void build(it s,it e,int l,int r,int v){
        if(l== r)return;
        int m = (l+r)>>1;
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        sumLeft[v].reserve(e-s+1);
        sumLeft[v].push_back(0);
        auto f = [m](int x){
            return x<=m;
        };
        for(it iter = s; iter!= e;iter++){
            mapLeft[v].push_back(mapLeft[v].back() + (*iter<=m));
            sumLeft[v].push_back(sumLeft[v].back() + (*iter<=m)*(rev[*iter]));
        }
        it p = stable_partition(s,e,f);
        build(s,p,l,m,v<<1);
        build(p,e,m+1,r,v<<1|1);
    }


    int kth(int i,int j,int k){
        j++;
        int l = 0,r = mx,u = 1,li,lj;
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

    int kthSum(int i,int j,int k){
        j++;
        int l = 0,r = mx,li,lj;
        int  si,sj;
        int ans = 0;
        int u = 1;
        while(l!=r){
            int m = (l+r)>>1;
            li = mapLeft[u][i],lj = mapLeft[u][j];
            si = sumLeft[u][i],sj = sumLeft[u][j];
            u<<=1;
            if(k<= lj-li){
                i = li,j = lj, r = m;
            }
            else {
                ans+=(sj-si);
                u|=1;
                i-=li,j-=lj,l = m+1,k-=(lj-li);
            }
        }
        ans+=rev[r]*k;
        return ans;
    }

    int l,r;
    int range(int i ,int j ,int a,int b){
        if( b<a || j<i)return 0;
        l = a,r = b;
        return range(i,j+1,0,mx,1);
    }

    int range(int i, int j,int a,int b,int v){
        if(b<l || a>r)return 0;
        if(a>=l && b<=r)return j-i;
        int m = (a+b)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        return range(li,lj,a,m,v<<1)+range(i-li,j-lj,m+1,b,v<<1|1);
    }
};

signed main(){__
    int n,t,l,r,k;
    cin>>n>>t;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;

    vector<int> u;
    vector<int> copy = nums;
    sort(copy.begin(),copy.end());
    u.push_back(copy[0]);
    int last = u.back();
    for(int i = 1;i<(int)copy.size();i++){
        if(copy[i]!=last){
            last = copy[i];
            u.push_back(last);
        }
    }
    rev.resize(u.size());
    for(int i = 0;i<n;i++){
        int idx = lower_bound(u.begin(),u.end(),nums[i])-u.begin();
        rev[idx] = nums[i];
        nums[i] = idx;
    }
    
    int mn = 0,mx = u.size()-1;
    wavelet wt(nums,mx);

    while(t--){
        cin>>l>>r>>k;
        l--,r--;
        int numW =  wt.kth(l,r,k);
        int num = rev[numW];
        int cont = wt.range(l,r,0,numW);
        int len = (r-l)+1;
        int sum = wt.kthSum(l,r,len)-wt.kthSum(l,r,cont);
        cout<<num<<" "<<sum<<endl;
    }
    return 0;
}