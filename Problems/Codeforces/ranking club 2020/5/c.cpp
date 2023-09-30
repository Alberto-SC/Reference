#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>b(100007,0);
    int cont = 0, mx = 0;
    for(int i=0; i<2*n; i++) {
        int a;
        cin>>a;
        if(b[a] == 0) cont++;
        else cont--;
        b[a]++;
        mx = max(cont,mx);
    }
    cout<<mx<<endl;
    return 0;
}