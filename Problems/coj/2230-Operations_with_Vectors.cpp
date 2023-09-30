#include <bits/stdc++.h>

using namespace std;
int main(){
	int n,ans = 0; 
	cin>>n;
	int a[n];
	int b[n];
	for(int i = 0; i<n; i++)
		cin>>a[i];
	for(int i = 0; i<n; i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	for(int i = 0; i<n; i++){	
		//cout<<a[i]<<","<<b[i]<<endl;
		ans +=a[i]*b[(n-i)-1];
	}

	cout<<ans<<endl;
	return 0;
}