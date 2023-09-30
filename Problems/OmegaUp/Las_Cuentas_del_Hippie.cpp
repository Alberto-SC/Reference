#include  <iostream>
using namespace std;
int main(){
	int a[60200];
	int c,n,j ,best = 200000;
	cin>>c>>n;
	for(int i = 0; i<n;i++){
		cin>>a[i];
		a[i+n] = a[i];
	}
	n *= 2;
	int cont = 0;
	for(int i = j = 0;i<n;i++){
		for( ;cont<c && j<n; j++)
			if(!a[j])cont++;
		if(cont == c && j-i-c < best)
			best = j-i-c;
		if(!a[i])cont--;
	}
	cout<<best<<endl;
	return 0;
}