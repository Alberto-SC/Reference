#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	string a[n][n];

	for(int i = 0;i<n;i++){
		for(int j = i;j<n-i;j++){
			if(i%2 == 0){
				a[j][i] = "X";
				a[j][(n-i)-1] = "X";
				a[(n-i)-1][j] = "X";
				a[i][j] = "X";
			}
			else{
				a[j][i] = ".";
				a[j][(n-i)-1] = ".";
				a[(n-i)-1][j] = ".";
				a[i][j] = ".";

			}
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)
			cout<<a[i][j];
		cout<<endl;
	}
}