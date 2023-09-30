#include <iostream>
#include <vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	vector<int> m(1000000,0);
	long long n,ni,moda = 0,aux;
	for(int i = 0;i<t;i++){
		cin>>n;
		moda = 0;
		for(int j = 0;j<n;j++){
			cin>>ni;
			m[ni]++;
		}
		for(int j = 1;j<=1000000;j++){
			if(m[j]>moda){
				moda = m[j];
				aux = j;
			}
		}
		cout<<aux<<"\n";
		m.clear();
		m.resize(1000000,0);
	}
	return 0;
}