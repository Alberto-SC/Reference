#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(n<m)swap(n,m);
    if(m == 1 )
        cout<<n<<endl;
    else if(n>2 && m>2)
        cout<<(n*m)-((n*m)/2)<<endl;
    else 
        cout<<2* (2*(n/4)+min(n%4,2));
    return 0;
}