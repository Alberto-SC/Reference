#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int mx = 1;
    int j = 0;
    for(int i = 1;i<n;i = j){
        j = i;
        int cont;
        if(nums[j]>nums[j-1]){
            cont = 1;
            while(j<n && nums[j]>nums[j-1]){
                cont++;
                j++;
            }
        }
        else j++;
        mx = max(cont,mx);
    }
    cout<<mx<<endl;
    return 0;
}