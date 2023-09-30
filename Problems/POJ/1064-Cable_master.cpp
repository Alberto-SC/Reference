#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
	int c,n,max = -10000,mid;
	float cn,res;
	cin>>c>>n;
	vector<float> ca;
	for(int i = 0;i<c;i++){
		cin>>cn;
		cn = cn*100;
		if(cn> max) max = cn;
		ca.push_back(cn);
	}
	int l = 1,r = max;
	while(l<= r){
		mid = (l+r)/2;
		int cont = 0;
		for(int i = 0;i<c;i++){
			cont+=ca[i]/mid;
		}
		//cout<<mid<<endl;
		if(cont >= n){
			l = mid+1;
			res = mid;
		}
		else 
			r = mid-1;
	}
	cout<< std::fixed;
	cout<< std::setprecision(2);
	cout<<res/100;
}