#include <bits/stdc++.h>
using namespace std;
#define print(A)for(atuo c:A)cout<<c<<" ";cout<<endl;
int main(){
    long long int  t,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        if(x==y+1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}