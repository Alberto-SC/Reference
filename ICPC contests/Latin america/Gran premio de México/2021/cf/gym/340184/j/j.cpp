#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;


int dfs(vector<vector<int>> &graph, vector<int> &weight, int me){
	if(graph[me].size() == 0){
		return weight[me] = 1;
	}

	int mn = 1000000;
	for(auto child:graph[me]){
		mn = min(mn, dfs(graph,weight,child)+1);
	}
	return weight[me] = mn;
}

void propagate(vector<vector<int>> &graph, vector<int> &weight, int me, int fatherCost){
	weight[me] = min(weight[me],fatherCost);

	for(auto child:graph[me]){
		propagate(graph, weight, child, weight[me]+1);
	}

	return;
}

const lli mod = 998244353;
lli bin_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}


int main(){
	int n; cin >> n;
	vector<vector<int>> graph(n);
	for(int i=1; i<n; i++){
		int dad; cin >> dad; dad--;
		graph[dad].push_back(i);
	}

	vector<int> weight(n);
	dfs(graph, weight, 0);
	propagate(graph, weight, 0, 1000000);

	lli p = 0, q = n;
	for(int el:weight){
		p += el;
	//	cout << el << " ";
	}
	//cout << endl;

	lli gcd = __gcd(p,q);
	p /= gcd;
	q /= gcd;
	//cout << "p=" << p << " q=" << q << endl;
    lli invq = bin_pow(q,mod-2);

	//p*q^-1 primo = 998244353
	cout << (p*invq)%mod << endl;

	return 0;

}
