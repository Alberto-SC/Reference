#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c1 = 0,c0= 0;
    string s;
    cin>>n>>s;
    for(int i = 0;i<n;i++){
        if(s[i] == '1')c1++;
        else c0++;
    }
    if(c1!= c0)cout<<1<<endl<<s<<endl;
    else {
        cout<<2<<endl;
        int cc1 = 0,cc0 = 0,i;
        for(i = 0;i<n;i++){
            if(cc1==c1 || cc0==c0)break;
            if(s[i]== '1')cc1++;
            else cc0++;
            cout<<s[i];
        }
        cout<<" ";
        for(i;i<n;i++){
            cout<<s[i];
        }
    }
}