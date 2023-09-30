#include <iostream>
#include <algorithm>
#include <iomanip>  
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

int main(){
	int p,q,r,s,t,u;
	double ec,fin,ini,mid;
	std::cout << std::fixed;
    std::cout << std::setprecision(4);
	while(cin>>p>>q>>r>>s>>t>>u){
		if(p*exp(-1)+q*sin(1)+r*cos(1)+s*tan(1)+t+u>1e-9 || p+r+u<0){
            cout<<"No solution\n";
            continue;
        }
		ini = 0.0;
		fin = 1.0;
		int cont = 0;
		while(cont < 30){
			cont++;
			mid  = (ini+fin)/2.0;
			ec = p*exp(-mid)+q*sin(mid)+ r*cos(mid) + s*tan(mid)+(t*(mid*mid)) +u;
			//cout<<x<<" "<<ec<<endl;
			if(ec > 0) ini = mid;
			else fin = mid;
		}
			cout<<ini<<endl; 

	}



}