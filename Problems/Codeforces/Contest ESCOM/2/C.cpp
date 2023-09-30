#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";
int ma = 2e7;
set<long long> b;
// mod(long long x){
    
// }
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
	ifstream cin("input.txt");
	ofstream cout("output.txt");
    int t=1;
    long long A,B,C;
    cin>>A>>B>>C;
    long long x = 1,nx;
    b.insert(x);
    for(int i = 0;i<ma;i++){
        nx = ( (A*x) + (x%B)  )%C;
        // cout<<"Xi  "<<nx<<endl;
        // if(b.find(nx) != b.end()){cout<<i+1;return 0;}
        // b.insert(nx);
         x = nx;
    }
    // cout<<nx<<endl;
    bool y = false;
    x = 1;
	long long  distance = -1, start = -1;
	for (int i = 0; i <= ma; i++) {
		if (x == nx) {
            // cout<<"HERE "<<i<<endl;
			if (y) {
				distance = i - start;
				break;
			}
			start = i;
			y = true;
		}
		x = ( (A*x) + (x%B)  )%C;
	}
    // cout<<distance<<endl;
	if (!(y && ~distance)) {
		cout << -1 << endl; return 0;
	}
	long long x1 = 1, x2 = 1;
	for (int i = 0; i < distance; i++) {
		x2 = ( (A*x2) + (x2%B)  )%C;
	}
	for (int i = 0; i < 2e7; i++) {
		if (x1 == x2) {cout << i + distance << endl;return 0;}
		x1 = ( (A*x1) + (x1%B)  )%C;
		x2 = ( (A*x2) + (x2%B)  )%C;
	}
    cin.ignore(), cin.get();
}