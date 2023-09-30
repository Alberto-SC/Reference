#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,l,r;
    cin>>n>>m;
    vector<bool>p(m+1,true);
    vector<int>free;
    for(int i = 0;i<n;i++){
        cin>>l>>r;
        for(int j = l;j<=r;j++)p[j] = false;
    }
    for(int i = 1;i<=m;i++)if(p[i])free.push_back(i);
    cout<<free.size()<<endl;
    for(auto c:free)cout<<c<<" ";
    cout<<endl;
    return 0;
}