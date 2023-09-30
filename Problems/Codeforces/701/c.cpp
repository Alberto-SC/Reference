#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n,x,y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        lli cont = 0;
        for(lli i = 1;i*i<=x;i++){
            if(i>y)break;
            if(((x-i)/i)-i<0)break;
            cont+=min(y-i,((x-i)/i)-i);
            // cout<<"I: "<<i<<" "<<((x-i)/i)-i<<endl;
        }
        cout<<cont<<endl;
    }
    return 0;
}  

