#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,k,s;
    cin>>n>>k>>s;
    if(k>s|| k*(n-1)<s)return cout<<"NO"<<endl,0;
    lli act =1;
    cout<<"YES"<<endl;
    while(k>0){
        int l= min(n-1,s-(k-1));
        act-l>0?act-=l:act+=l;
        cout<<act<<" ";
        s-=l;
        k--;
    }
    return 0;
}