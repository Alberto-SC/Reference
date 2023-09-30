#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli k,s,g;

lli gauss(lli n){
	return (n*(n+1))/2;
}

lli f(lli n){
	lli ans = s*n;
	ans += k*gauss(n-1);
	return ans;
}

int main(){__
	int t; cin >> t;
	lli lo,hi,md,sol, it;
	while(t--){
		cin >> k >> s >> g;
		lo = 1, hi = g/k+100;
		md = (lo+hi)/2;
		it = 45;
		while(it--){
			sol = f(md);
			if(sol > g){
				hi = md;
			}else{
				lo = md;
			}
			md = (lo+hi)/2;
		}
		cout << hi << endl;
	}
	return 0;
}  


