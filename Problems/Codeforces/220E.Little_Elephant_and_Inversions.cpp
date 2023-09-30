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

    void build(it s,it e,int l,int r,int v){
        if(l == r)return ;
        int mid= (l+r)>>1;
        auto f = [mid](int x){
            return x<=mid;
        };
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        for(it i =s;i!= e;i++)
            mapLeft[v].push_back(mapLeft[v].back()+ (*i<=mid));
        it p = stable_partition(s,e,f);
        build(s,p,l,mid,v<<1);
        build(p,e,mid+1,r,v<<1|1);
    }

    int l,r;
    int range(int i,int j,int a,int b){
        // cout<<"RANGE "<<a<<" "<<b<<" "<<i<<" "<<j<<endl;
        if(j<i || b<a || a>=mx||b <0)return 0;
        l = a,r = b;
        return range(i,j+1,0,mx-1,1);
    }
    int range(int i,int j,int a,int b,int v){
        // cout<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
        if(a>r || b<l)return 0;
        if(a>=l && b<=r)return j-i;
        int mid = (a+b)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        return range(li,lj,a,mid,v<<1)+range(i-li,j-lj,mid+1,b,v<<1|1);
    }
    
};
int main(){
    lli n,k;
    cin>>n>>k;
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
        if(copy[i] != last){
            last = copy[i];
            uniques.push_back(last);
        } 
    }

    for(int i = 0;i<n;i++)
        nums[i]= lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();  
    lli inv = 0;
    int l = 0,r = n-1;
    if(nums[l]>nums[r])inv++;
    if(inv>k)return cout<<0<<endl,0;
    wavelet wt(nums,uniques.size());
    for(int i = 1;i<=n-2;i++){
        l++;
        lli C1 =wt.range(n-1,n-1,0,nums[l]-1);
        C1+= wt.range(0,l-1,nums[l]+1,uniques.size());
        inv+= C1;
    }
    lli ans = 0;
    // cout<<l<<endl;
    for(int r = n-1;r>0;r--){
        // cout<<inv<<" "<<r<<" "<<l<<endl;
        if(l== r)l--;
        while(inv>k && l>0){
            // cout<<r<<" "<<l<<endl;
            lli C2 =wt.range(r,n-1,0,nums[l]-1);
            C2+= wt.range(0,l-1,nums[l]+1,uniques.size());
            inv-=C2;
            l--;
            // cout<<inv<<endl;
        }
        // cout<<l<<endl;
        lli C1 =wt.range(0,l,nums[r-1]+1,uniques.size());
        // cout<<"Left "<<C1<<endl;
        C1+= wt.range(r,n-1,0,nums[r-1]-1);
        // cout<<"Right "<<C1<<endl;
        if(inv<=k)
            ans+=l+1;
        if(r-1!= l)
            inv+=C1;
        // cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}