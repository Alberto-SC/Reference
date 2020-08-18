#include <bits/stdc++.h>
using namespace std;
lli mod_mult(lli a, lli b){
	lli x = 0;
	while(b){
		if(b & 1)	x = (x + a);
		a = (a << 1);
		b >>= 1;
	}
	return x;
}

unsigned int hashh(unsigned int x) {
    x = mod_mult(((x >> 16) ^ x) ,0x45d9f3b);
    x = mod_mult(((x >> 16) ^ x),0x45d9f3b);
    x = (x >> 16) ^ x;
    return x;
}

unsigned int unhash(unsigned int x) {
    x = mod_mult((x >> 16) ^ x, 0x119de1f3);
    x = mod_mult((x >> 16) ^ x , 0x119de1f3);
    x = (x >> 16) ^ x;
    return x;
}
int main(){
    int n;
    set<int> hashes;
    for(int i = 0;i<10000000;i++){
        hashes.insert(hashh(i));
    }
    cout<<hashes.size();
    return 0;
}