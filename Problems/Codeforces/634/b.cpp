#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        string s = string(n,'a');   
        for(int i =0;i<n;i++)s[i] = (char)(i%b)+'a';
        cout<<s<<endl;
    }
    return 0;
}