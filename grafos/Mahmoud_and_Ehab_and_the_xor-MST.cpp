#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dist;
    for(int i = 0;i<n;i+=2){
        dist.push_back(i^i+2);
    }
    for(auto c:dist)cout<<c<<" ";
    cout<<endl;
    return 0;
}