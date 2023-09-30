#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,k,n;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n%2 == k%2 && n>=k){
            cout<<"YES"<<endl;
            cout<<n-(k-1)<<" ";
            for(int i = 0;i<k-1;i++)cout<<1<<" ";
            cout<<endl;
        }
        else if(n%2 == 0&& n>=2*k){
            cout<<"YES"<<endl;
            cout<<n-(2*(k-1))<<" ";
            for(int i = 0;i<k-1;i++)cout<<2<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}