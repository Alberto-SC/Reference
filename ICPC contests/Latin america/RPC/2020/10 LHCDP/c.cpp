  
#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int base,r; cin >> base >> r;
	vector<int> height(base+1, 0);

	int b,h,shift, mx;
	while(r--){
		cin >> b >> h >> shift;
		mx = 0;
		for(int i=shift; i<shift+b; i++){
			mx = max(mx, height[i]);
		}
		mx += h;
		for(int i=shift; i<shift+b; i++){
			height[i] = mx;
		}
	}

	mx = 0;
	for(int i=0; i<=base; i++)
		mx = max(mx, height[i]);

	cout << mx << endl;

	return 0;
}