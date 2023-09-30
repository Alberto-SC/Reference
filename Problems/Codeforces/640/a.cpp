#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nu;
        while(n){
            nu.push_back(n%10);
            n/=10;
        }
        int cont = 0;
        int p = 1;
        for(auto &c: nu){if(c!=0)cont++;c*=p;p*=10;}
        cout<<cont<<endl;
        for(auto c:nu)if(c!=0)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}