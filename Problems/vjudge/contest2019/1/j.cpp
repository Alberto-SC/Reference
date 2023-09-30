#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long a,b,k;
    while(t--){
        cin>>a>>b>>k;
        long long n = k/2;
        long long ans;
        if(k&1)
            if(k == 1)ans = a;
            else ans = (n*(a-b))+a; 
        else
            ans = n*(a-b);
        cout<<ans<<endl;
    }
}