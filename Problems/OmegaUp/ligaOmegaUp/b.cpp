#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    vector<int> b(n+1,0);
    for(auto &c:nums)cin>>c,b[c]++;
    cout<<b[k];
    return 0;
}