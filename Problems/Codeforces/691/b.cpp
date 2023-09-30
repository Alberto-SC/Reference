#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>n;
    vector<lli> N;
    if(n%2 == 0){
        lli x = (n/2)+1;
        cout<<x*x<<endl;
    }
    else{
        lli x = n/2;
        lli y = 2*((x+2)*(x+1));
        cout<<y<<endl;
    }
    return 0;
}  

