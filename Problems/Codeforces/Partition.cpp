#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int a = 0,b = 0;
    for(auto &c:nums)cin>>c,c<0?a+=c:b+=c;
    cout<<b-a<<endl;
    return 0;
}