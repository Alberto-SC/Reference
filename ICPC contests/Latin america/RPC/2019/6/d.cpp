#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i,j,n,tr;
    cin>>j>>i;
    while(j!= 0&& i!= 0){

        n = (i+j)-1;
        if(n&1){
            cout<<((n*(n+1))/2)-(n-i)<<endl;
        }
        else{
            long long  a = (((n-1)*n)/2)+1;
            cout<<a+(n-i)<<endl;
        }
        cin>>j>>i;
    }

    return 0;
}