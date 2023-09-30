#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAX = 1005;
int p[MAX], deg[MAX], ans[MAX];
int res(int i){return (i==ans[i] ? i : ans[i] = res(p[i]));}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i = 1; i<=n; ++i){
		cin>>p[i];
        ++deg[p[i]];
	}          
    queue<int> q;
	for(int i = 1; i<=n; ++i)ans[i] = i;
	for(int i = 1; i<=n; ++i)if(deg[i]==0)
		q.push(i);
	while(!q.empty()){ 
		int nn = q.front();q.pop();
		--deg[p[nn]];ans[nn] = p[nn];
		if(deg[p[nn]]==0)q.push(p[nn]);
	}
    for(int i = 1; i<=n; ++i)
		cout << res(i) << ' ';
	                     

   return 0;
}