#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
typedef long long int lli;

int main(){

	lli n, lim; cin >> n;
	bool is1 = false, is4 = false;
	if(n == 2){
		cout << 1 << endl;
	}else if(n%3 == 1){
		lim = n/3 - 1;
		cout << lim*7 + 4 << endl;
	}else if(n%3 == 2){
		lim = n/3;
		cout << lim*7 + 1 << endl;
	}else{
		lim = n/3; 
		cout << lim*7 << endl;
	}

	return 0;
}