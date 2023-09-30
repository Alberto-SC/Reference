#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,b;
    cin>>t;
    while(t--){
        cin>>n;
        int cont =0;
        for(int i=0;i<n;i++){
            cin>>b;
            if(b>=n)cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}
