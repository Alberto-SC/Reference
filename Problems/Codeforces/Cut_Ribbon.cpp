#include <bits/stdc++.h>
#define ld long long
using namespace std;

int main(){
	ld n, a, b, c;
	cin >> n >> a >> b >> c;
	ld dp[n+1];
	fill(dp, dp+n+1, -1e10); dp[0]=0;
	for (ld i=a; i<=n; i++) dp[i]=max(dp[i], dp[i-a]+1);
	for (ld i=b; i<=n; i++) dp[i]=max(dp[i], dp[i-b]+1);
	for (ld i=c; i<=n; i++) dp[i]=max(dp[i], dp[i-c]+1);
	cout << dp[n];
    return 0;
}