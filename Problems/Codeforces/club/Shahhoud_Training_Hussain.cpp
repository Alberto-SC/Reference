#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    long long int t,k,p,n;
    cin>>t;
    while(t--){
        cin>>k>>p>>n;
        cout<<(k-min(k,p))*n<<endl;
    }
    return 0;
}