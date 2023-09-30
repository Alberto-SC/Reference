#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
int gpn1,gpn2;
int DP[101];
using namespace std;
int s(int n){
	if(n < 0 ) return 0;
	if(DP[n] != -1)	return DP[n];		 
	for(int i = 1 ; i<= ceil(sqrt(n)) ; i++){
 		if(i == 1){
 			gpn1 = (i*((3*i)-1))/2;                //Generalized pentagonal numbers 
			DP[n] = s(n-gpn1);
 			gpn2 = (-i*((3*-i)-1))/2;
			DP[n] += s(n-gpn2);
 		}
 		else{	
 			if(i%2 == 0){
 				gpn1 = (i*((3*i)-1))/2;    
 				DP[n] -= s(n-gpn1);
 				gpn2 = (-i*((3*-i)-1))/2;
 				DP[n] -= s(n-gpn2);
 			}
 			else{
 				gpn1 = (i*((3*i)-1))/2; 
 				DP[n] += s(n-gpn1);
 				gpn2 = (-i*((3*-i)-1))/2;
 				DP[n] += s(n-gpn2);	
 			} 
 		}
	}
	return DP[n];
}
int main(){
	int n;
	DP[0] =1;
	for(int i = 1; i<101;i++){
		DP[i] = -1;
	}
	cin>>n;
	printf("%d \n",s(n));
}