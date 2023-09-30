#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    string sa,sb;
    cin>>sa>>sb;
    if(b<a-1)return cout<<"NO"<<endl,0;
    int i;
    for(i = 0 ;i<a;i++)if(sa[i]=='*')break;
    if(i == a){if(sa!= sb)return cout<<"NO"<<endl,0;else return cout<<"YES"<<endl,0;}
    for(int j = 0;j<i;j++)if(sa[j] != sb[j])return cout<<"NO"<<endl,0;
    int nn = a-(i+1);
    int k = a-1,l = b-1;
    while(nn--){
        if(sa[k]!= sb[l])return cout<<"NO"<<endl,0;
        k--;l--;
    }
    cout<<"YES"<<endl;  
    return 0;
}