#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main(){
	int n,count = 0;
	string a;
	vector<int> l(27,0);
	vector<int> ll(27,0);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>a;
		for(int j = 0; j <a.size();j++)
			if(ll[a[j]-'a']!=1) l[a[j]-'a']++,ll[a[j]-'a']= 1;
		ll.clear();
		ll.resize(27,0);
	}
	for(int i = 0;i<l.size();i++){
		if(l[i]==n) 
			count++;
	}
	cout<<count;
}