#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
vector<int> bit;
int N = 1000007;
int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < N; idx += idx & -idx) bit[idx] += delta;
}

int main(){
    int n,t,x;
    cin>>n;
    bit.resize(N,0);
    for(int i = 0;i<n;i++){
        cin>>t>>x;
        if(t == 1)add(x,1);
        else cout<<sum(x)<<endl;
    }
}