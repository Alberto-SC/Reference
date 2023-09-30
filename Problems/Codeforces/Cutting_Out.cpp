#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
int n,k,ai;
vector<int> b(maxn);

bool check(int m){
    int times = 0;
    for(int i = 1;i<maxn;i++)
        times+= b[i]/m;
    if(times<k)return false;
    return true;
}

void print(int m){
    int times = 0;
    for(int i = 1;i<maxn;i++){
        int x = b[i]/m;
        for(int j = 0;j<x;j++){
            if(times== k)break;
            cout<<i<<" ";
            times++;
        }
    }
}
int main(){
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>ai;
        b[ai]++;
    }

    int l = 1,r = 200007;
    while(l<r){
        int m = (l+r+1)>>1;
        if(check(m))
            l = m;
        else r = m-1;
    } 
    print(r);
    return 0;
}