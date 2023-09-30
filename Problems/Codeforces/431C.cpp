// K-tre___DP
#include <bits/stc++.h>
using namespace std;


const int mod = 1e9 + 7;
int dp[100][2];

int main(){
    int n,k,d:
    cin>>n>>k>>d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    return 0;
    vector<long long> A(n+1), AR(n+1);
	for(int i = 0;i<=k;i++){
            A[i] = 1;
            if(i < d) AR[i] = 1;
    }
	A[0] = 0, AR[0] = 0;
    for(int i = 1;i<n+1;i++){
		for(int j = 1;j<k+1;j++){ 
			if (i < j) break;
			A[i] = (A[i] + A[i-j]) % MOD;
		}
	}
	FOR(i, 1, n+1) {
		FOR(j, 1, k+1) {
			if (i < j) continue;
			if (j < d) AR[i] = (AR[i] + AR[i-j]) % MOD;
		}
	}
	cout << (A[n] - AR[n] + MOD) % MOD << endl;
	return 0;
}