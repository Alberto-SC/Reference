#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<bool> Primos(1000,true);
void sieve(){
	for(int i = 2; i*i<1000;i++){
		if(Primos[i])
			for(int j = 2;j*i<1000;j++)
				Primos[j*i]= false;
	}
}

int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0); 
	int n,m;
	cin>>m;
	sieve();
	while(m--){
		string sn;
		cin>>sn;
		n = 0;
		for(int i = 0;i<sn.size();i++)
			n +=sn[i]-'0';
		if(Primos[n])cout <<"UltraPrimo"<<endl;
		else cout<<"No UltraPrimo"<<endl;
	}


}