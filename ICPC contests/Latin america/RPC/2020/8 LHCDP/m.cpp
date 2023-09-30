#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;

ll tam;
bitset<1000100> bs;
vi primes;

void sieve(ll upperbound){
	tam=upperbound+1;
	bs.set();
	bs[0]=bs[1]=0;
	for(ll i=2; i<=tam ; i++){
		if(bs[i]){
			for(ll j= i*i; j<=tam; j+=i){
				bs[j]=0;
			}
      primes.push_back(i);
		}
	}

}

ll sumDiv(ll N){
	ll idx=0, ans=1, ini=N;
	while(primes[idx] <= N && idx<primes.size()){
		ll power=0;
		while(N%primes[idx]==0){ N/=primes[idx] ; power++;}
    // cout<<ans<<endl;
		if(power!=0)ans*=((pow(primes[idx],power+1)-1))/(primes[idx]-1);
		++idx;
	}
	if(N!=1) ans*=(pow(N,2)-1)/(N-1);
	return ans-ini;
}


int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve(1000009);
	ll t,num;
  cin>>t;
  while(t--){
    cin>>num;
    ll res= sumDiv(num);
    if(num==res)
      cout<<"perfect\n";
    else if(res<num)
      cout<<"deficient\n";
    else
      cout<<"abundant\n";
  }
	return 0;
}
