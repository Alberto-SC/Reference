#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,s,to;
    cin>>t;
    while(t--){
        cin>>n>>s>>to;
        int both =(s+to)-n; 
        if(s+to==n)cout<<max(s,to)+1<<endl;
        else if(s+to == 2*n)cout<<1<<endl;
        else cout<<max(s-both,to-both)+1<<endl;
    }
    return 0;
}