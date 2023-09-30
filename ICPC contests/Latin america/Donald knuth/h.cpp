#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mn = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == i+1)continue;
            while(nums[i]!= i+1){
                swap(nums[i],nums[nums[i]-1]);
                mn++;
            }
        }
        if(k<mn)cout<<"No"<<endl;
        else {
            int diff = k-mn;
            if(diff%2 ==0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}