#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	if(next_permutation(a.begin(),a.end()))
		cout<<a<<endl;
	else
		cout<<0<<endl;
	return 0;
 }
