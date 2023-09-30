#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define endl "\n"

using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { 
	const uint64_t C = lli(4e18 * acos(0)) | 71; 
	lli operator()(lli x) const { return __builtin_bswap64((x^RANDOM)*C); }
};

int main(){__
	int m,n;
	while(cin >> m >> n){
		if(m == 0 && n == 0){
			break;
		}

		lli num, inter=0, AmB, BmA;
		// unordered_set<lli> a;
        gp_hash_table<lli, int, chash> a({},{},{},{}, {1 << 16});
		for(int i=0; i<m; i++){
			cin >> num;
			a[num]++;
		}

		for(int i=0; i<n; i++){
			cin >> num; 
			if(a.find(num)!= a.end()){
				inter++;
			}
		}

		AmB = m - inter;
		BmA = n - inter;

		cout << AmB << " " << inter << " " << BmA << " " << AmB+inter+BmA << endl;
	}

	return 0;
}
