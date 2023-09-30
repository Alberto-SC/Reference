#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
using namespace std;
typedef signed long long ll;
int mod=998244353;
int A[100077];
int B[100077];
int N[100077];
int dp[100077];
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n,k,ai;
	cin>>n>>k;
    dp[0]=1;
	ll sum=1;
	for(int i=1;i<=n;i++) {
		cin>>ai;
		for(int j=B[ai];j<A[ai];j++)
            if(--N[j]==k) 
                sum+=dp[j];
		for(int j=A[ai];j<i;j++)
            if(++N[j]==k+1) 
                sum-=dp[j];
		sum%=mod;
		dp[i]=sum;
		B[ai]=A[ai];
		A[ai]=i;
		sum=(sum+dp[i])%mod;
	} 
	cout<<(dp[n]%mod+mod)%mod<<endl;
    return 0;
}
