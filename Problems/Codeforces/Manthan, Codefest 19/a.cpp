#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,a,b,n;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        int pos[3] = {a,b,a^b};
        cout<<pos[n%3]<<endl;
    }
    return 0;
}