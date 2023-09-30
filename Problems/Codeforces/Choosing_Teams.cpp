#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,c+=k;
    int cont = 0;
    for(int i = 0;i<n;i++)if(nums[i]<=5)cont++;
    cout<<cont/3<<endl;
    return 0;
}