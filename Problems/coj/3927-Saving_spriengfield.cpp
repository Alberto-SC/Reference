#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
typedef  double Double;
Double eps = 1e-8;

struct b{
	Double x,h;
};
vector<b> E;

Double mini(Double &x){
		Double  r = 0;
		for(b & bu : E){
			r = max(r, hypot(bu.x-0.5-x, bu.h));
			r = max(r, hypot(bu.x+0.5-x, bu.h));
		}
		return r;
};
int main(){
	int n;
	cin>>n;
	E.resize(n);
	for(int i = 0;i<n;i++)
		cin>>E[i].x>>E[i].h;
	Double l = -10,r = 20000,m;
	while(true){
		if(abs(r-l)<eps){
			m = l + (r - l) / 2;
			break;
		}
		Double ml = l+(r-l)/3;
		Double mr = l+2*(r-l)/3;
		if(mini(ml)>mini(mr)){
			l = ml;
		}
		else
			r = mr;
	}
	cout<< fixed<<setprecision(9)<<mini(m)<<endl;
	return 0;
}





