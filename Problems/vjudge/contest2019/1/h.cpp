#include <bits/stdc++.h>
using namespace std;

int main(){
    int magicNumbers[] ={1,14,144};
    string a;
    cin>>a;
    int n = a.size();
    for(int i = 0;i<n;i++){
        if(a[i] != '1' && a[i]!= '4'){cout<<"NO";return 0;}
        if(a[0] == '4'){cout<<"NO";return 0;}
        if(a[i] == '4' && a[i+1]== '4' && a[i+2]== '4'){cout<<"NO";return 0;}
    }
    cout<<"YES"<<endl;
    return 0;
}