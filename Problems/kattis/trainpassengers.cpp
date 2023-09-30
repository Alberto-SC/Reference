#include <bits/stdc++.h>
using namespace std;
int main(){
    int c,n,in,left,wait,dentro=0;
    bool impossible = false;
    cin>>c>>n;
    for(int i =0;i<n;i++){
        cin>>left>>in>>wait;
        if(i == n-1 && in>0)impossible =true; 
        if(i == n-1 && dentro-left>0)impossible =true;
        if(i == n-1 && wait>0)impossible =true;
        if(dentro-left<0)impossible=true;
        if(left >0 && i==0)impossible =true;
        dentro -=left;
        if(dentro+in>c)impossible =true;
        if(c-(dentro+in)>0&&wait>0)impossible=true;
        else dentro +=in;
    }
    if(impossible)
        cout<<"impossible";
    else 
        cout<<"possible";
    return 0;
}