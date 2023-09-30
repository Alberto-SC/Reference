#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define print(A)for(auto c:A)cout<<c<<" ";
int ans = 0,b,size;
vector<vector<int>> Mem;
vector<long long> PrimeFact;
vector<int> fr;
vector<int> primes;
void criba(int n){
	vector<bool> isPrime(n+1,true);
    for (int i=2; i<=n; ++i){
		if(isPrime[i])
			primes.push_back(i);
		for(int p: primes){
			int d = i*p;
			if(d>n)break;
			isPrime[d] = false;
			if( i % p == 0)break;
		}	
	}  
}

map<long long int,int> fact;
vector<int> frec;
void getFactorization(long long int x) { 
	for(long long int p: primes){
		if(p*p >x)break;
		int pot = 0;
    	while (x % p == 0) { 
			pot++;
			x /= p; 
    	} 
		if(pot) fact[p]+=pot;
	}
	if(x>1)fact[x]++;
} 
int DP(int currentPrime,int mult){
	cout<<currentPrime<<" "<<mult<<endl;
	if(Mem[currentPrime][mult] != 0)return Mem[currentPrime][mult];
	if(currentPrime == size && mult != b)return 0;
	if(currentPrime == size && mult == b)return 1;
	for(int i = 0;i<=fr[currentPrime];i++)
		Mem[currentPrime][mult]+= DP(currentPrime+1,mult*(i+1))%mod;
	if(mult >b)return 0;
	return Mem[currentPrime][mult];|1|

}
int main(){
    int n;
    long long ai;
    cin>>b>>n;
	criba(1000000);
    for(int i = 0;i<n;i++){
        cin>>ai;
        getFactorization(ai);
    }
	for(auto it = fact.cbegin(); it != fact.cend(); ++it){
        PrimeFact.push_back(it->first);
        fr.push_back(it->second);
    }
	// print(fr)cout<<endl;
	size = fr.size();
	Mem.resize(size +1);
	for(int i = 0;i<size+1;i++)
		Mem[i].resize(b+1,0);
    DP(0,1);
	for(int i = 0;i<size +1;i++)
		for(int j = 0;j<b+1;j++)
			cout<<Mem[i][j]<<" \n"[j == b];
    cout<<Mem[0][1];

}