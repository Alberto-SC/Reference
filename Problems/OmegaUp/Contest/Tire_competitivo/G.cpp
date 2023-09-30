#include <iostream>

using namespace std;
int main(){
		int n;
		cin>>n;
		int A[n][n];
		int A1[n][n];
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				cin>>A[i][j];
			
		for(int i = 0,i1 = n-1;i<n;i++,i1--)
			for(int j = 0;j<n;j++)
					A1[j][i1] = A[i][j];
			
	
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				cout<<A1[i][j]<<" ";
			}
			cout<<"\n";
		}
}