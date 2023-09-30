#include <iostream> 
#include <algorithm>
#include <regex>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string a;
	regex e1("o");
	regex e2("b");
	regex e3("d");
	regex e4("j|k|x"); 
	getchar();
	for(int i = 0;i<n;i++){
		getline(cin,a);
		reverse(a.begin(),a.end());
		a  = regex_replace(a,e1,"'");
		a  = regex_replace(a,e2,"h");
		a  = regex_replace(a,e3,"g l'w");
		a  = regex_replace(a,e4," Cthughht'");
		cout<<a<<endl;
	}	
}