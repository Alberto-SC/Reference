#include <bits/stdc++.h>
using namespace std;

int N = 4;

void display(unsigned int *a){
    for(int x = 0; x < N; x++)
        cout<<a[x]<<" ";
    cout<<endl;
} 

void QuickPerm(void){
    unsigned int a[N], p[N+1];
    register unsigned int i, j, tmp;
    for(i = 0; i < N; i++){
        a[i] = i ;   
        p[i] = i;
    }
    p[N] = N;
    display(a);  
    i = 1;   
    while(i < N){
        p[i]--;          
        j = i % 2 * p[i];  
        tmp = a[j];         
        a[j] = a[i];
        a[i] = tmp;
        display(a);
        i = 1;              
        while (!p[i]){
            p[i] = i;       
            i++;     
        }
    } 
} 

int main(){
    int n;
    QuickPerm();
    return 0;
}