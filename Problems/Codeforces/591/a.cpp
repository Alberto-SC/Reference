#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;

int main(){
    int q,n;
    cin>>q;
    while(q--){
        cin>>n;
        if(n  ==1)cout<<3<<endl;
        else if(n == 2)cout<<2<<endl;
        else if(n&1)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}