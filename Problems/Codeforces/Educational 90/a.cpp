#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t;
    lli a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if(a>=c)cout<<-1<<" ";
        else cout<<1<<" ";

        if(b==1 && c == 1)cout<<-1<<endl;
        else if(b == 1 && c>a)cout<<-1<<endl;
        else if(a*b<=c)cout<<-1<<endl;
        else if(a*b>c)cout<<b<<endl;
    }
    return 0;
}