#include <bits/stdc++.h> 
using namespace std; 
#define N 100000 
int arr[N]; 
struct wavelet_tree { 
    int low, high; 
    wavelet_tree* l, *r; 
    vector<int> freq; 
    wavelet_tree(int* from, int* to, int x, int y) { 
        low = x, high = y; 
        if (from >= to) 
            return; 
        if (high == low) { 
            freq.reserve(to - from + 1); 
            freq.push_back(0); 
            for (auto it = from; it != to; it++)  
                freq.push_back(freq.back() + 1); 
            return; 
        } 
        int mid = (low + high) / 2; 
        auto lessThanMid = [mid](int x) { 
            return x <= mid; 
        }; 
        freq.reserve(to - from + 1); 
        freq.push_back(0); 
        for (auto it = from; it != to; it++)  
            freq.push_back(freq.back() + lessThanMid(*it));         
        auto pivot = stable_partition(from, to, lessThanMid); 
        l = new wavelet_tree(from, pivot, low, mid); 
        r = new wavelet_tree(pivot, to, mid + 1, high); 
    } 
    int kOrLess(int l, int r, int k) { 
        if (l > r or k < low) 
            return 0; 
        if (high <= k) 
            return r - l + 1; 
        int LtCount = freq[l - 1]; 
        int RtCount = freq[r]; 
        return (this->l->kOrLess(LtCount + 1, RtCount, k) +  
             this->r->kOrLess(l - LtCount, r - RtCount, k)); 
    } 
  
}; 
  
int main(){
    int n,q,l,r,a,b;
    cin>>n>>q; 
    int nums[n];
    int high = -1;
    for(auto &c:nums)cin>>c,high=max(c,high);

    wavelet_tree wt(nums,nums+n,1,high); 
    for(int i = 0;i<n;i++){
        cin>>l>>r>>a>>b;
        l--,r--;
        int ans1 = wt.kOrLess(l,r,b);
        int ans2 = wt.kOrLess(l,r,a-1);
        cout<<ans1<<" "<<ans2<<endl;
        cout<<ans1-ans2<<endl; 
    }

    return 0; 
} 