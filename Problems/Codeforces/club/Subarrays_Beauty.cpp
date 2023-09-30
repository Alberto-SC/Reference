#include <bits/stdc++.h>
typedef long long lli;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t,n;
    lli ans;
    cin>>t;
	while (t--) {
		ans = 0;
		cin>>n;
        vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin>>nums[i];
		for (int k = 0; k <= 22; k++) {
			int cont = 0;
			for (int i = 0; i < n; i++){
				int bit = (nums[i] >> k) & 1;
				if (bit) 
					cont++;
				else {
					ans += (lli)cont * (cont + 1) / 2 * (1 << k);
					cont = 0;
				}
			}
			ans += (lli)cont * (cont + 1) / 2 * (1 << k);
		}
		cout<<ans<<"\n";
	}
	return 0;
}