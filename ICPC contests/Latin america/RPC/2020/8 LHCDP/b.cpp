#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct wavelet{
    int lo;
    int hi;
    wavelet *left, *right;
    vector<int> mapLeft;
    wavelet(vector<int>:: iterator from, vector<int>:: iterator to ,int x,int y):lo(x),hi(y){
        if(from >= to)
            return; 
        int m = (lo + hi)>>1;
        auto f = [m](int x){
            return x <=m;
        };
        mapLeft.reserve(to- from +1);
        mapLeft.push_back(0);
        for(auto it = from; it!= to;++it){
            auto leq = f(*it);
            mapLeft.push_back(mapLeft.back()+leq);
        }
        if(hi != lo){ b 
            auto pivot = stable_partition(from, to,f);
            left = new wavelet(from, pivot, lo,m);
            right = new wavelet(pivot, to,m+1,hi);
        }
    }


    int kth(int l ,int r,int k){
        if(l> r)
            return -1;
        if(lo == hi)
            return lo;
        int lb = mapLeft[l-1], rb = mapLeft[r];
        int inLeft = rb-lb;
        if(k<=inLeft)
            return left->kth(lb+1,rb,k);
        else 
            return right->kth(l-lb,r-rb,k-inLeft);
    }
    
};


int main(){__
    int t,n,q,l,r,k;
    while(cin>>n>>q){
        vector<int> nums(n);
        vector<int> copy(n);
        vector<int> real(n);
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
        wavelet wt(nums.begin(), nums.end(),*min_element(nums.begin(), nums.end()),*max_element(nums.begin(), nums.end()));
        for(int i = 0;i<q;i++){
            cin>>l>>r>>k;
            cout<<uniques[wt.kth(l,r,k)]<<endl;
        }
    }
    return 0;
}