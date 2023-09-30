#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d,thom;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>a>>b>>c>>d;
        if(i == 0)thom = a+b+c+d;
        nums[i] = a+b+c+d;
    }
    sort(nums.begin(),nums.end());
    cout<<n-(upper_bound(nums.begin(),nums.end(),thom)-nums.begin())+1<<endl;

    return 0;
}