#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int n; cin >> n;
	bool isEven=false, isOdd=false;

	for(int i=1; i<=100; i++){
		int sum = 0;
		for(int j=0; j<n; j++){
			sum += i+j;
		}
		if(sum%2==0){
			isEven = true;
		}else{
			isOdd = true;
		}
	}

	if(isEven && isOdd){
		cout << "Either" << endl;
	}else{
		if(isEven)
			cout << "Even" << endl;
		else
			cout << "Odd" << endl;
	}


	return 0;
}