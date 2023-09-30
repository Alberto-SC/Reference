#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int f = min(m,n/k);
        // cout<<f<<endl;
        cout<<f-ceil((double)(m-f)/(k-1))<<endl;
    }
    return 0;
}