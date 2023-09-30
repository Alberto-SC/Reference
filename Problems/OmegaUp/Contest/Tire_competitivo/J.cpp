#include <iostream>
#include <vector>

using namespace std;

vector<bool> boolprimes(1000001,true);

void numeros_primos(){
	boolprimes[0] = false;
	boolprimes[1] = true;
	for(long long  i = 2;i<1000001;i+= 2)boolprimes[i] =false;
	for(long long  i = 3;i<1000001;i+= 2){
		if(boolprimes[i])
			for(long long  j = i*i;j<1000001;j+= 2*i)boolprimes[j] = false;
	} 
}

int main(){
	int p,pi;
	numeros_primos();
	cin>>p;
	for(int i = 0;i<p;i++){
		cin>>pi;
		if(pi == 2)
			cout<<"2\n";
		else{	
			while(!boolprimes[pi]) pi--;
			cout<<pi<<"\n";
		}
	}

}