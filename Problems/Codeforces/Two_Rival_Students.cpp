#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,x,a,b;
    cin>>t;
    while(t--){
        cin>>n>>x>>a>>b;
        if(b<a)swap(a,b);
        int mnr = min(n-b,x);
        b = b+mnr;
        x-= mnr; 
        if(x>0){
            int mnl = min(a-1,x);
            a-=mnl;
            x-=mnr;
        }
        cout<<b-a<<endl;
    }
    return 0;
}