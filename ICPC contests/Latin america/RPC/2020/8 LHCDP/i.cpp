#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int lli;

using namespace std;

int main(){
	fast_io
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		priority_queue<pair<int,int>> pq;
		vector<int> freq(n+1);
		vector<string> name(n+1);

		for(lli i=0; i<n; i++){
			cin >> name[i] >> freq[i];
			pq.emplace(-freq[i], -i);
		}

		while(k--){
			auto top = pq.top(); pq.pop();
			cout << -top.first << " " << name[-top.second] << endl;
			pq.emplace(top.first - freq[-top.second], top.second);
		}

	}
	
	return 0;
}