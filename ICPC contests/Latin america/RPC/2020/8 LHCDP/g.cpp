#include<bits/stdc++.h>
#define MOD 1000000007

typedef long long int ll;

using namespace std;

ll modularInverse(ll a, ll m){
	ll r0 = a, r1 = m, ri, s0 = 1, s1 = 0, si;
	while(r1){
		si = s0 - s1 * (r0 / r1), s0 = s1, s1 = si;
		ri = r0 % r1, r0 = r1, r1 = ri;
	}
	if(r0 < 0) s0 *= -1;
	if(s0 < 0) s0 += m;
	return s0;
}
ll mod(ll a){
  return ((a%MOD)+MOD)%MOD;
}

ll multMod(ll a, ll b){
	ll ans = 0;
	a %= MOD, b %= MOD;
	ans= mod(a*b);
	return ans;
}



ll gaussMod(ll N){
	ll mult= multMod(N,N+1);
	ll res= multMod(mult, modularInverse(2,MOD));
	return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int t;
	ll N;
	cin>>t;
  int caseid=1;
	while(t--){
		cin>>N;
    ll ancho= floor(N/2.0)+1,alto=1;
    ll last = gaussMod(N);
    ll sumFirstRow = mod(mod(gaussMod(last))-mod(gaussMod(mod(last-ancho))));
    // cout<<"->"<<sumFirstRow<<endl;
		if(N%2!=0){ // CUADRADO
      alto=ancho;
		}else{ // RECTANGULO
      alto=ancho-1;
		}
    sumFirstRow=multMod(sumFirstRow,alto);
    int act=N;
    for(int i=alto-1; i>0; i--){
      sumFirstRow-= multMod(multMod(act--,ancho),i);
      sumFirstRow=mod(sumFirstRow);
    }
    cout<<"Case #"<<caseid++<<": "<<sumFirstRow<<"\n";
	}
	return 0;
}