#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli sum(int r){
    if(r == 0)return 0;
    int x = r/2;
    int z = r-x;
    return (x*(x+1))-(z*z);

}
int main(){
    lli q,l,r;
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>l>>r;
        lli a = sum(r);
        lli b = sum(l-1);
        cout<<a-b<<endl;
    }

    return 0;
}