#include <iostream>
using namespace std;

int main(){
	int n;
	string A,B;
	cin>>A>>B;
	cin>>n;
	string C[n];
	C[0] = A;
	C[1] = B;
	for(int i = 2;i<n;i++){
		C[i] = C[i-2]+C[i-1];
	}
	cout<<C[n-1];
}