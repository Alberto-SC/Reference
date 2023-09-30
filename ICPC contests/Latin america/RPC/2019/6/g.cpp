#include <bits/stdc++.h>
using namespace std;
int mod_mult(int a, int b, int mod){
	int x = 0;
	while(b){
		if(b & 1)	x = (x + a) % mod;
		a = (a << 1) % mod;
		b >>= 1;
	}
	return x;
}

int mod_pow(int a, int n, int mod){
	int x = 1;
	while(n){
		if(n & 1)	x = mod_mult(x, a, mod);
		a = mod_mult(a, a, mod);
		n >>= 1;
	}
	return x;
}
bool witness(int a, int s, int d, int n){
	int x = mod_pow(a, d, n);
	if (x == 1 || x == n - 1) return false;
	for(int i = 0; i < s - 1; i++)
	{
		x = mod_mult(x, x, n);
		if (x == 1) return true;
		if (x == n - 1) return false;
	}
	return true;
}

bool isPrime(int n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int d = n - 1, s = 0;
	while (d % 2 == 0) ++s, d /= 2;
	int test[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 0};
	for (int i = 0; test[i] && test[i] < n; ++i)
		if (witness(test[i], s, d, n))
			return false; // composite
	return true; // probably prime
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    while(cin>>n){
        if(!n&1)cout<<2;
        else if(isPrime(n))cout<<1;
        else if(isPrime(n-2))cout<<2;
        else cout<<3;
        cout<<endl;
    }
}