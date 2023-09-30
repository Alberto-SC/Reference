#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,r;
    cin>>t;
    while(t--){
        cin>>n>>r;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int cont = 0;
        for(int i = n-1;i>=0;i--){
            if(nums[i]-(r*cont)<=0)break;
            int j = i;
            while(nums[i]== nums[j]){
                j--;

            }
            i = j+1;
            // cout<<i<<endl;
            cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}