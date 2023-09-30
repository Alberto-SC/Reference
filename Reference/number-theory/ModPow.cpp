/**
 * Author: Alberto silva
 * Source: folklore
 * Description: Binary exponentiation modulo m
 * Status: tested
 */
const int mod = 1e9+7;
int modpow(int a,int b){
	int x = 1;
	while(b){
		if(b&1) (x*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return x;
}