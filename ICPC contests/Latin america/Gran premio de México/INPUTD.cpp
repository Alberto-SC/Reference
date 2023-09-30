#include <iostream>

using namespace std;

int main(){
	int cont = 0;
	for(int i = 1;i<1000000;i+=2){
		if(i% 5 != 0){
			cont++;
			cout<<i<<endl;
		}
	}
	cout<<cont;

}