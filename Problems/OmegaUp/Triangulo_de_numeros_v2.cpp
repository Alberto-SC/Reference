#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<"1"<<endl;
	for(int i = 2;i<=n;i++){
		int nt = (i*(i+1))/2;
		for(int j = 0;j<i;j++){
			cout<<nt<<" ";
			nt--;
		}
		cout<<endl;
	}
}