#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int ll;


map<ll, ll> F;

ll f(ll n) {
	// if(n==0) return 0;
	if (F.count(n)) return F[n];
	ll k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % MOD;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % MOD;
	}
}



int main(){__
    ll N,M;
    cin>>N>>M;
    int last=0;
    int act;
    F[0]=F[1]=1;
    ll numOfWays = 1;
    int numberOfRocks = 0;

    vector<int> v;
    while(M--){
        cin>>act;
        v.push_back(act);
    }
	v.push_back(N+1);
	last = v[0];
    numOfWays = f(v[0]-1);
    for(int i=1; i<v.size(); i++){
        act=v[i];
        numberOfRocks=act-last-1;
		if(numberOfRocks<=0){
			cout<<"0\n";
			return 0;
		}
		// cout<<numberOfRocks<<endl;
        numOfWays = (numOfWays * f(numberOfRocks-1))%MOD;
        last = act;
    }

    cout<<numOfWays<<"\n";
    return 0;
}