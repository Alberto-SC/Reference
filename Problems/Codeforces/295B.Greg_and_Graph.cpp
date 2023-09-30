#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int lli;
const lli maxn = 507;
lli adj[maxn][maxn];

int main(){__
    int n;
    cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
            cin>>adj[i][j];
		}
	}
    vector<int> x(n);
    for(auto &c:x)cin>>c,c--;
	reverse(x.begin(), x.end());
	vector<lli> ans;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				adj[x[j]][x[k]] = min(adj[x[j]][x[k]], adj[x[j]][x[i]] + adj[x[i]][x[k]]);
			}
		}
		lli res = 0;
		for(int j=0; j<=i; j++){
			for(int k=0; k<=i; k++){
				res += adj[x[j]][x[k]];
			}
		}
		ans.push_back(res);
	}
    reverse(ans.begin(),ans.end());
    for(auto c: ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}
