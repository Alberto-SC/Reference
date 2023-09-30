#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        lli x = b-a;
        if(x>a){
            cout<<a<<endl;
        }
        else{
            lli ans = x;
            a-=x;
            b-=2*x;
            if(a>b)swap(a,b);
            if(a%3==1 && b%3==2)
                ans+= ((a/3)*2)+1;
            else if(a%3==2 && b%3 == 2)
                ans+= ((a/3)*2)+1;
            else 
                ans+= (a/3)*2;
            cout<<ans<<endl;
        }
    }
    return 0;
}  

