#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int fi,next,N;
	cin>>fi>>next>>N;

	for(int i=0; i<N;i++){
		long long int cons=0, cost=0,act=0;
		cin>>act;
		cout<<act<<" ";
		if(act>1000){
			cost= 1000*fi;
			cost+= (act-1000)*next; 
		}else{
			cost= act*fi;			
		}
		cout<<cost<<"\n";
	}
	return 0;
}