#include <iostream>

using namespace std;

int main(){
	cin.tie(0);
    ios_base::sync_with_stdio(0);       
    std::ios::sync_with_stdio(0); 	
    string a;
    int n = 0;
    int yes = 0;
    while(!getline(cin,a).eof()){
    	for(int i = 0;i<a.size();i++){
    		if ((a[i]>=65 and a[i]<=90) or (a[i]>=97 and a[i]<=122))yes = 1;
			if((a[i]<65 || (a[i]>90 && a[i]<97) || a[i]>122) && yes == 1){	
				n++;
				yes = 0;
			}
    	}
    	if(yes == 1)n++;
    	yes = 0;
    	cout<<n<<"\n";
    	n  = 0;
    }
}