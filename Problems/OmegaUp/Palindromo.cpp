#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
char* quitarEspacios(char* str) { 
    char* temp; 
    for(int i = 0; i < str.size(); i++) 
        if(str[i] != ' ') temp += str[i];
        
 
    return temp; 
} 
int main(){
	int n,i,j = 0;
	cin>>n;
	char a[n];
	getchar();
	for(i = 0;i<n;i++)
		scanf("%c",&a[i]);
	for(i = 0;i<=n/2;i++) {
		if(a[i] != a[(n-i)-1]){	
			j = 1 ;
			break;
		} 
	}
	if(j == 0)cout<<"SI";
	else cout<<"NO";
	
}