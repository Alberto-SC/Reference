#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    for(int i = 0;i<n;i++)
        cin>>b[i];
    for(int i = 0;i<10000;i++){
        bool yes = true;
        for(int j = 0;j<n;j++) {
            if (a[j] + i > b[j]) break;
            else if (a[j] + i < b[j])yes = false;
        }
        if(yes){cout<<i<<endl;return 0; };
    }
}