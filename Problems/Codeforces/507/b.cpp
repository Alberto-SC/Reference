#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,f;
    cin>>n>>k;
    f = (k*2)+1;
    cout<<ceil(n/(f*1.0))<<endl;
    int howquit = f-(n%f),quitleft = howquit/2,init = (k-quitleft)+1;
    if(n%f == 0)init = k+1;
    for(int i = 0;i<ceil(n/(f*1.0));i++){
        cout<<init<<" ";
        init+=f;
    }
    cout<<endl;
    return 0;
}