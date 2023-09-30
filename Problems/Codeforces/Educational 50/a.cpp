#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
int main(){
    lli n,k,ans;
    cin>>n>>k;
    if(k%n!=0)
        cout<<k/n+1<<endl;
    else
        cout<<k/n<<endl;
    return 0;
}