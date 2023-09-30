#include <iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
	long long arr[n];
	long long ac[n];
		for(int i = 0;i<n;i++)
			cin>>arr[i];
		for(int i = 1;i<n;i++)
			arr[i] += arr[i-1];
		for(int i = 0;i<n;i++)
			cout<<arr[i]<<" ";
	}
	return 0;
}
