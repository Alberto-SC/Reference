#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
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
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
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
        for(int i = 0;i<n;i++)
            nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
        vector<int> copy2 = nums;
        wavelet wt(nums,uniques.size());
        nums = copy2;
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.rbegin(),v.rend());
        int l = n-1;
        vector<int> p[nums.size()+7];
        bool flag = true;
        for(int i = 0;i<n;i++){
            int x = wt.range(0ll,v[i].second-1,v[i].first,nums.size());
            int y = wt.range(v[i].second+1,n-1,0,v[i].first);
            int parity = x+y;
            if(parity&1 && p[v[i].first].size() && p[v[i].first].back()&1){
                p[v[i].first].back()++;
                parity++;
            }
            p[v[i].first].push_back(parity);
            l--;
        }
        for(int i = 0;i<nums.size();i++){
            if(p[i].size()==0)continue;
            for(auto v:p[i]){
                if(v&1)flag = false;
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
