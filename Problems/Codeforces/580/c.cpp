#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(!(n&1))return cout<<"NO"<<endl,0;
    cout<<"YES\n";
    bool mas = true,nu = 0;
    vector<int >nums(2*n);
    for(int i = 1;i<=n;i++){
        if(mas){
            nums[i-1] = (i*2)-1;
            nums[(i+n)-1] = (i*2);
        }
        if(!mas){
            nums[i-1] = (i*2);
            nums[(i+n)-1] = (i*2)-1;
        }
        nu++;
        mas = !mas;
    }
    for(auto c:nums)cout<<c<<" ";
    cout<<endl;
    return 0;
}