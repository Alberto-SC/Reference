#include <bits/stdc++.h>
using namespace std;
int main(){
    long long  n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(),nums.end());
    long long ans = nums[n/2];
    long long  cont = 1;
    for(int i = (n/2)+1;i<n;i++){
        if(((nums[i]-ans)*cont)<=k){
            k-=(nums[i]-ans)*cont;
            ans = nums[i];
            cont++;
        }
    }
    ans+=k/cont;
    cout<<ans<<endl;
}