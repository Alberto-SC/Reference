#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int x = 0,last = 0;
        while(1){
            int x = k/n;
            x-=last;
            if(x == 0)break;
            k+=x;
            last += x;
        }
        cout<<k<<endl;
    }
    return 0;
}