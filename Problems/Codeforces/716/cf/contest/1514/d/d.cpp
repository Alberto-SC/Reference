#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef vector<int>::iterator it;
struct wavelet{
    vector<vector<int>> mapLeft;
    int mx;
    wavelet(vector<int> &A,int mx):mapLeft(mx*2),mx(mx){
        build(A.begin(),A.end(),0,mx,1);
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

    int rank(int c,int i){
        i++;
        int l = 0,r = mx-1,u = 1,m,left;
        while(l!= r){
            m = (l+r)>>1;
            left = mapLeft[u][i];
            u<<=1;
            if(c<=m)
                i = left,r = m;
            else 
                i-=left,l = m+1,u|=1;
        }
        return i;
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
    int l,r;
    int range(int i ,int j ,int a,int b){
        if( b<a || j<i)return 0;
        l = a,r = b;
        return range(i,j+1,0,mx-1,1);
    }

    int range(int i, int j,int a,int b,int v){  
        if(b<l || a>r)return 0;
        if(a>=l && b<=r)return j-i;
        int m = (a+b)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        return range(li,lj,a,m,v<<1)+range(i-li,j-lj,m+1,b,v<<1|1);
    }


    int minimun_of_ocurrences(int i,int j,int k){
        return minimun_of_ocurrences(i,j+1,k,1,0,mx);
    }  
    int minimun_of_ocurrences(int i,int j,int k,int v ,int l,int r ){
        if(l == r)return j-i>= k?l:mx+2;
        if(j-i<k)return mx+2;
        int m = (l+r)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        int c = lj-li;
        int ans= mx+2;
        if(c >=k)
            ans = min(ans,minimun_of_ocurrences(li,lj,k,v<<1,l,m));
        if((j-i)-c>=k)
            ans = min(ans,minimun_of_ocurrences(i-li,j-lj,k,v<<1|1,m+1,r));
        if(c <k && (j-i)-c<k)return mx+2;
        return ans;
    }

};


signed main(){
    int t,n,q,l,r,k,c,a,b;
    cin>>n>>q;
    vector<int> nums(n);
    vector<int> copy(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        copy[i] = nums[i];
    }
    sort(copy.begin(),copy.end());
    vector<int> uniques;
    int last = copy[0];
    uniques.push_back(copy[0]);
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(copy[i]);
        }
    }
    vector<int> o[n];
    for(int i = 0;i<n;i++){
        nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
        o[nums[i]].push_back(i);
    }
    wavelet wt(nums,uniques.size());
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        int len = (r-l)+1;
        int mx = (len/2)+(len%2)+1;
        int x = wt.minimun_of_ocurrences(l,r,mx);
        int idxl = lower_bound(o[x].begin(),o[x].end(),l)-o[x].begin();
        int idxr = upper_bound(o[x].begin(),o[x].end(),r)-o[x].begin();
        int count = idxr-idxl;
        int y = len-count;
        // cout<<mx<<" "<<x<<" "<<count<<" "<<y<<" "<<uniques.size()<<endl;
        if(x == uniques.size()+2)cout<<1<<endl;
        else 
            cout<<count-y<<endl;
    }
    return 0;
}
