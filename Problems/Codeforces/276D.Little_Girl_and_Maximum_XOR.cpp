#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli get_pow(lli n){
    lli x= 1;
    int cont = 0;
    while(x<=n){
        x<<=1;
        cont++;
    }
    return  cont-1;
}
int main(){
    lli l,r;
    cin>>l>>r;
    if(l == r)return cout<<0<<endl,0;
    int n  = get_pow(l),n2 = get_pow(r);
    if(n!= n2)return cout<<(1ll<<(n2+1))-1<<endl,0;
    lli mid = 1ll<<n2;
    bool flag = true;
    while(1){
        if(flag)
            mid += (1ll<<n2)/2;
        else
            mid -= (1ll<<n2)/2;
        if(r>= mid && l<=mid-1)break;
        else if(l>= mid)
            flag = true;
        else if(r<= mid-1)
            flag = false;
        n2--;
    }
    cout<<(1ll<<n2)-1<<endl;
    return 0;
}