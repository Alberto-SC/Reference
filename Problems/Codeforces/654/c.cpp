#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    lli t,a,b,n,m;
    cin>>t;
    while(t--){
        cin>>a>>b>>n>>m;
        if(min(a,b)<m){cout<<"No"<<endl;continue;}
        if(a<b){
            a-=m;
            if(a+b>=n)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else {
            b-=m;
            if(a+b>=n)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        };
        
    }
    return 0;
}