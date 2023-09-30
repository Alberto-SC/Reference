#include<bits/stdc++.h>
using namespace std;
int DP[20000];
void ini(){
	for(int i = 0; i<20000;i++){
		DP[i] = -1;
	}
}
int s(int n,int k){
	if(n == 0)
	   return 1;
	if(n < 0)
		return 0; 
	if(DP[n] != -1)
		return DP[n];	
	for(int i = 1;i<=k;i++)
 	 DP[n] = s(n-i,k);
    	
}
int main(){
	int n,q,k;
    cin>>q;
    while(q--){
        cin>>k>>n;
	    ini();
        cout<<s(n,k)<<endl;
    }
	
}
