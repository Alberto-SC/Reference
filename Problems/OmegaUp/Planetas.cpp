#include <iostream>
#include <vector>
#include <iomanip>  
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
	int n,p,cont = 0;
	long double error = 1e-11,r,l,s,m;
	cin>>n;
	vector<int> pl;
	for(int i = 0;i<n;i++){
		cin>>p;
		pl.push_back(p);
	}
	sort(pl.begin(),pl.end());
	cout<<n-1<<endl;
	for(int i = 0;i<n-1;i++){
		l = pl[i];
		r = pl[i+1];
		int cont = 0;
		while(cont<25){
			cont++;
			double g = 0;
			m = (l+r)/2;
			for(int j = 0;j<n;j++){
				 g += 1/(pl[j]-m);
			}
			if(g >0) r = m;
			else l = m;

		}
		std::cout << std::fixed;
    	std::cout << std::setprecision(3);
    	cout<<l<<" ";
	}
	return 0;

}