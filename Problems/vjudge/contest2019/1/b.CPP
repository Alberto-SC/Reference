#include <bits/stdc++.h>
using namespace std;
int main(){
    int b,k,a;
    cin>>b>>k;
    long long even = 0;
    for(int i = 0;i<k;i++){
        cin>>a;
        if(i == k-1){
            if(a&1)even += 1;
            else even += 0;
        }
        else{
            if( a&1 && b&1)even += 1;
            else even += 0;  
        }
    }
    if(even &1)cout<<"odd";
    else cout<<"even";
    return 0;
}
