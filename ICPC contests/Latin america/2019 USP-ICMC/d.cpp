#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int idx = 0;
    for(int i = 0;i<a.size();i++)
        if(a[i] == b[idx])idx++;
    
    if(idx==b.size())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}