#include <iostream>

using namespace std;
long long int gcd(long long int a,long long b){
	long long int r;
  while(b) r = a%b, a = b,b= r;
  return a;
}

int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0); 
	unsigned long long   a,b,n;
	cin>>n;

	while(n--){
		cin>>a>>b;
    	if(gcd(a,b) == 1) cout<<"SI"<<endl;
    	else cout<<"NO"<<endl;
	}
    return 0;
}	