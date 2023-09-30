#include <iostream>
#include <string>
using namespace std;
int main(){
	int max =0 ;
	string a;
	for(int i = 0;i<10;i++){
		cin>>a;
		if(a.size() > max) max = a.size();
	}
	cout<<"El nombre mas largo tiene "<<max<<" letras.";
}