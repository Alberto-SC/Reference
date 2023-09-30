#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    bool yes = true;
    for(int i= 0;i<n;i++)
        cin>>a[i];
    // for(int i = 0;i<n;i++)
    //     if(i-1>= 0 && i+1<n && a[i]>a[i-1]+a[i+1])yes = false;
    // if(yes){
        vector<int> b(n+1);
        b[0] = 0;
        int mn = 1000000000;
        int mnp =1000000000;
        for(int i= 1;i<n+1;i++){
            b[i] = a[i-1]-b[i-1];
            if(i&1)mnp =min(mnp,b[i]);
            mn = min(mn,b[i]);
        }
        mn = abs(mn);
        if(mnp<0)cout<<0;
        else{
        mnp = abs(mnp);
        cout << (abs(mn) <= abs(mnp) ? abs(mnp - mn) + 1 : 0) << endl;
        }
        // cout<<abs(abs(mn)-abs(mnp))+1<<endl;
    // }
    // else cout<<0<<endl;
    return 0;
}