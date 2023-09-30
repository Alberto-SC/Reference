#include <bits/stdc++.h> 
using namespace std;
int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(b == a)cout<<0<<endl;
        else  if(b>a){
            if((b-a)&1)
                cout<<1<<endl;
            else cout<<2<<endl;
        }
        else {
            if((a-b)%2 == 0){
                cout<<1<<endl;
            }
            else cout<<2<<endl;

        }
    }
    return 0;
}
