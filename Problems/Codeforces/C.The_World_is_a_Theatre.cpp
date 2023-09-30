#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<vector<int>> conbina(40,vector<int>(40));
const int  MAXN = 40;
lli bc[MAXN][MAXN];

lli binomial_Coeff(int n,int m){ 
	int i,j;
	for (i=0; i<=n; i++) bc[i][0] = 1;
	for (j=0; j<=n; j++) bc[j][j] = 1;
	for (i=1; i<=n; i++)
	    for (j=1; j<i; j++)
	        bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	return bc[n][m];
}

int main(){
    int n,m,t;
    cin>>n>>m>>t;
    if(n+m)
    binomial_Coeff(35,35);
    vector<int> combinam(min(t-4,m)+1);
    lli ans = 0;
    for(int i = 4,j = min(t-4,m);i<=min(n,t-1);i++)
        i+j == t?ans+= bc[n][i]*bc[m][j--]:ans+=0;
    cout<<ans<<endl;
    return 0;
}