#include <bits/std++.h>

using namespace std;
vector<bool> primes;
void criba(int n){
	vector<bool> c(n+5,true);
	c[0] = c[1] = false;
	for(int i = 4;i<=n;i+=2)
		c[i] = false;
	for(int i = 3;i<=n;i+=2){
		if(c[i])
			for(int j = i*i;j<=n;j += 2*i)
				c[i] = false;
	}
	for(int i = 0;i<n;i++){
		if(c[i]) primes.push_back(i);
	}
}

int pw(int b,int e){
	int ans = 1;
	while(e){
		if(e&1)
			ans *= b;
		e>>=1;
		b*=b;
	}
	return ans;
}

map<int, int> factorizar_factorial(int n){
    map<int, int> f;
    for(int i=0;i<primos.size();i++){
        int d = primos[i];
        if(d>n) break;
        int contador = 0;
        int j = 1;
        while(true){
            int tmp = n/fast_pow(d, j);
            contador += tmp;
            if(tmp == 0) break;
            j++;
        }
        f[d] += contador;
    }
    return f;
}


int main(){
	ios_base::sync_with_stdio(0);
	int maxim = 0,n;
	vector<int>casos;
	while(1){
		cin>>n;
		if(!n)break;
		casos.push_back(n);
		maxim = max(n,maxim);
	}
	criba(maxim);
	for(int i:casos){
		


	}

}