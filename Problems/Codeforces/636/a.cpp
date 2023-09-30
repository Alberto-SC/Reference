#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int res;
        for(int i = 2;i<31;i++){
            int pw = 1<<i;
            if(n%(pw-1)==0){res = n/(pw-1);break;}
        }
        cout<<res<<endl;
    }
    return 0;
}