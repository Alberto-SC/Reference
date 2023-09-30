#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,p,c;
    cin>>t;
    while(t--){
        cin>>n;
        int lastp = 0,acc= 0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            cin>>p>>c;
            if(p<lastp)flag = false;
            if(p<lastp+c)flag = false;
            if(p<acc)flag = false;
            lastp = p;
            acc+=c;
        }
        !flag?cout<<"NO"<<endl:cout<<"YES"<<endl;

    }
    return 0;
}