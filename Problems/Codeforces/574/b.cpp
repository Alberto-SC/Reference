#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long l = 0,r = n,mid;
    while(r>=l){
        long long mid = l + ((r-l)/2);
        // cout<<mid<<"  ";
        long long p = ((mid*(mid+1))/2)-(n-mid);
        // cout<<p<<endl;
        if (p==k){cout<<n-mid<<endl;break;}   
        else if(p>k)r = mid-1;
        else l= mid+1; 
    }
    return 0;
}