#include <iostream>
using namespace std;
int main(){
	string a;
	string b;
	int moda =1,modb = 1;
	cin>>a;
	cin>>b;
	for(int i = 0;i<a.length();i++){
		//printf("%d  ",a[i]-'A'+1);
		moda *= ((a[i]-'A')+1)%47;
	}
	moda %=47;
	//printf("\n");
	for(int i = 0;i<b.length();i++){
		//printf("%d  ",b[i]-'A'+1);
		modb *= ((b[i]-'A')+1)%47;
	}
	modb %=47;
	if(moda == modb)cout<<"GO"<<endl;
	else cout<<"STAY"<<endl	;
}