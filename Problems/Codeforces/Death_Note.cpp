#include <bits/stdc++.h>
using namespace std;
#define finish(x)return cout<<x<<endl,0;
typedef long long int lli;
int main(){
    lli n,m,x;
    cin>>n>>m;
    lli sum = 0;
    for(int i = 0;i<n;i++){
        cin>>x;
        sum+=x;
        if(sum>=m){
            cout<<sum/m<<" ";
            sum = sum%m;
        }
        else cout<<0<<" ";
 
    }
    return 0;
}