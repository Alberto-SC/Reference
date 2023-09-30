#include <iostream>
using namespace std;
typedef unsigned long long ull;

int fact(ull a ,ull b){
	int cont = 0;
	ull copya = a,copyb = b;
	while(a%2 == 0&& b%2 == 0){
		a/= 2;
		b/= 2;
		cont++;
	}

	int i = 3;
	while(a != 1 ||  b != 1  &&i<sqrt(copya)&& i<sqrt(copyb)){
		while(a%i== 0&& b%i == 0){
			cont ++;
			a/=i;
			b/=i;
		}
		i+=2;
	}

}
int main(){
	ull a,b;
	cin>>a>>b;
	cout<<fact(a,b);


}