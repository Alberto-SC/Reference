#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
map<lli,lli>fact;
const int N = 10000000;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}



int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    lli n,t,cnt,i;
    criba();
    while(true){
        cin>>n;
		if(!n)
			break;
		cnt = 0;
		while(n % 2 == 0){
			cnt++;
			n /= 2;
		}
		if(cnt > 0)
			cout<<2<<"^"<<cnt<<" ";
		i = 3;
		
		while(i*i <= n && n != 1){
			cnt = 0;
			while(n % i == 0){
				n /= i;
				cnt++;
			}
			if(cnt > 0)
				cout<<i<<"^"<<cnt<<" ";
			i += 2;
		}
		if(n > 1)
			cout<<n<<"^1 ";
		cout<<"\n";
}
    return 0;
}