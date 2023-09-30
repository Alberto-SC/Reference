#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli trail_fact(lli n,lli b){
    lli ans = 1000000000000000000LL;
	for (lli i=2; i<=b; i++) {
		if (1LL * i * i > b) i = b;
		int cnt = 0;
		while (b % i == 0) {b /= i; cnt++;}
		if (cnt == 0) continue;
		lli tmp = 0, mul = 1;
		while (mul <= n / i) {mul *= i; tmp += n / mul;}
		ans = min(ans, tmp / cnt);
	}
    return ans;
}
int main(){
    lli  n,b;    
    cin>>n>>b;

	cout << trail_fact(n,b) << endl;
    return 0;
}