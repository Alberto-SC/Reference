#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli prime(lli x){
	lli j,flag=0;
	lli o=(lli)sqrt(x);
	for(j=2;j<=o;j++)
		if(x%j==0){
			flag=1;
			break;
		}
	if(flag==0) return 1;
	else return 0;
}
int main(){
	lli i,k,c,m;
	double n;
	while(true){
        cin>>n;
        if(n == 0)break;
		lli m=(lli)sqrt(n);
		for(i=2;i<=m;i++){
			c=0;
			if(n%i==0){
				lli k=n/i;
				if(prime(i)==1){
					while(n%i==0){
						c++;
						n=n/i;		
					}
					printf("%lld^%lld ",i,c);
				}
				c=0;
				if(k!=i){
					if(prime(k)==1){
						while(n%k==0){
							c++;
							n=n/k;		
						}
						printf("%lld^%lld ",k,c);
					}
				}
				if(n==1)
				break;
			}
		}
		printf("\n");
		scanf("%lld",&n);
	}
	return 0;
}
