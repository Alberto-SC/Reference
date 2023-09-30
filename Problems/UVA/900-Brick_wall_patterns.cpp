#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	long long  f[52];
	int i;
	f[1] = 1; f[2] = 2; 
	for (i = 3; i <= 51; i++)
		f[i] = f[i-1] + f[i-2];

	while(cin>>n && n){
		cout<<f[n]<<endl;
	}
	return 0;
}