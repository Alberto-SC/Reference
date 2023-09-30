#include <iostream>
#include <cmath>
using namespace std;
typedef long long int Long;
bool Exponenciar(Long a, Long n) {
	Long r = 1;
    Long y = a;
    while (n){	
        if (n%2)r = r * y
        n = n/2
        y = y * y
   	    r = r*y
    }
    if( )
    return r

int main(){
	int n, i = 0;
	while(true){
		if(exp(n,i))break;
		i++
	}
	return 0;
}