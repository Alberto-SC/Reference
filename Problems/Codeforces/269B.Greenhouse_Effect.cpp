#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a;
    cin>>n>>m;
    double x;
    vector<int> t;

    for(int i = 0;i<n;i++){
        cin>>a>>x;
        auto idx = upper_bound(t.begin(),t.end(),a);
        if(idx == t.end())t.push_back(a);
        else *idx = a;
    }
    cout<<n-t.size()<<endl;
    return 0;
}