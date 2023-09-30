#include <bits/stdc++.h>
using namespace std;
typedef long double Double;
int main(){
	int n;
	Double h;
	cin>>n>>h;
	Double area = h/2;
	Double arean= area/n;
	Double angR = .5/h;
	int cont = 1;
	Double b2 = 0,b = 0;
	int Nn = n-1;
	Double res =0;
	while(Nn){
		Double l= 0,r = h;
		cont = 0;
		while (cont<40){
			cont++;
	        Double m = (l+r)/2;
	        if(Nn == n-1)
				b = m*angR;
	        else
	        	b = (m+res)*angR;
	        //cout<<b<<" "<<m<<" "<<b2<<endl;
	        if(Nn == n-1){
	        	if((b*m) < arean)
	            	l = m;
	        	else
	            	r = m;
	        }
	        else{
	        	if( ((b+b2)*m) < arean)
					l = m;
				else
					r = m;
	        }
		}
		b2 = b;
		Nn--;
		h = h-l;
		res += l;
		std::cout << std::fixed;
	    std::cout << std::setprecision(12);
		cout<<res<<endl;
	}
	
	return 0;
}