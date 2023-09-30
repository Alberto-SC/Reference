#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define EPS 0.0000001

using namespace std;

typedef long long int lli;

bool eq(double a, double b){
	return abs(a-b) < EPS;
}

int main(){
	int t; cin >> t;
	while(t--){
		int a,s; cin >> a >> s;
		vector<double> v(a);

		double total=0, cal=0, prom=0;
		for(auto &x:v){
			cin >> x;
			total += x;
		}

		while(s--){
			double sum = 0;
			int r1,r2,r3, up,down;
			for(int i=0; i<a; i++){
				cin >> cal;
				cal /= 100;
				sum += cal*v[i];
			}
			sum /= total;
			r2 = round(sum/0.05);
			r1 = r2-1;
			r3 = r2+1;
			if(r1*0.05 <= sum && r2*0.05 > sum){
				up = r2;
				down = r1;
			}else if(r2*0.05 <= sum && r3*0.05 > sum){
				up = r3;
				down = r2;
			}

			if(eq(sum,down*0.05)){
				cout << (int)down*0.05*100 << " SAME" << endl;
			}else if(eq(sum,up*0.05)){
				cout << (int)up*0.05*100 << " SAME" << endl;
			}
			else{
				double difDown = abs(sum-down*0.05), difUp = abs(sum-up*0.05);
				if(difDown <= difUp){
					cout << (int)down*0.05*100 << " DOWN" << endl;
				}else{
					cout << (int)up*0.05*100 << " UP" << endl;
				}
			}
		}
		cout << endl;
		
	}

	return 0;
}
