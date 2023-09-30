#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int lli;

using namespace std;

vector<int> divs;
void getdivs(int n){
	divs = vector<int>();
    for(int i = 1;i*i<=n;i++){
        if(n%i == 0){
        	divs.push_back(i);
            if(n/i != i)divs.push_back(n/i);
        }
    }
}

int main(){
	fast_io
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		getdivs(n);

		int sum = 0;
		for(auto num:divs){
			if(num != n) sum += num;
		}
		
		if(sum < n)
			cout << "deficient" << endl;
		else if(sum == n)
			cout << "perfect" << endl;
		else
			cout << "abundant" << endl;
	}
    

	return 0;
}