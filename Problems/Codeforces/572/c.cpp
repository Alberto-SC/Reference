#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q,l,r;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    cin>>q;
    for(int i = 1;i<n;i++)
        nums[i] +=nums[i-1];
    
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        cout<<(nums[r-1]-(l-2<0?0:nums[l-2]))/10<<endl;
    }
    return 0;
}