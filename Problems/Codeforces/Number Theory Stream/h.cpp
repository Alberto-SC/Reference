#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli phi (lli n){
	lli result = n;
	for (lli i=2; i*i<=n; ++i)
		if(n %i==0){
			while(n %i==0)
			n /= i;
			result -= result / i;
	}
	if (n > 1)
	result -= result / n;
	return result;
}


int main(){__
	lli t= 1,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<phi(b/__gcd(a,b))<<endl;
    }
    return 0;
}  

