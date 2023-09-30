#include <iostream>
using namespace std;

int main(){
	int h1,h2,m1,m2,dh,dm;
	cin>>h1>>m1;
	cin>>h2>>m2;
	if(m1> m2){
		dm=(60-m1)+m2;
		h1++;
		if(h1 >h2) dh = (24-h1)+h2;
		else dh = h2-h1;
	}  
	else {
		dm = m2-m1;
		if(h1 >h2) dh = (24-h1)+h2;
		else dh = h2-h1;
	}
	cout<<dh<<endl<<dm;


}