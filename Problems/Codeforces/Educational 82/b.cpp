#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,n,g,b;
    cin>>t;
    while(t--){
        cin>>n>>g>>b;
        lli cuantos = ceil(n/2.0);
        if(g>n)cout<<n<<endl;
        else{
            lli bads = n-cuantos;
            lli how = ceil(cuantos/(g*1.0));
            lli x = ((how-1)*b)+cuantos;
            if(b*how>=bads)cout<<x<<endl;
            else
                cout<<x+(n-x)<<endl;
        }
    }
}