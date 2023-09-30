#include <iostream>
#include <string>
using namespace std;
int main(){
	string a;
	string b;
	cin>>a;
	cin>>b;
	string temp = a + a;
	if((temp.find(b) != string::npos))
		cout<<"NO";
	else cout<<"SI";

}

