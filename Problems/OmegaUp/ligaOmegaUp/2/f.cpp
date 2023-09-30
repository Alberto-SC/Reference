#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c;
    for(int i = 0;i<n;i++)cout<<a[i]+b[i]<<" ";
    cout<<endl;
    return 0;
}