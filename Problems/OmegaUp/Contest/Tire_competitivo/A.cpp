#include <iostream>
using namespace std;
int main(){
	int m,n,c = 1;
	cin>>m>>n;
	for(int i = 0;i<m;i++){
		if(i%2 != 0) c+=n-1;
		else c=(i*n)+1;
		for(int j = 0;j<n;j++){
			if(i%2 == 0){
				cout<<c<<" ";
				c++;
			}
			else{
				cout<<c<<" ";
				c--;
			}
		}
		cout<<"\n";
	}
	return 0;
}