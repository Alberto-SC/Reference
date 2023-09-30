#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int T,n,cont = 1;
	cin>>T;
	while(T--){
		int soli = 0,solj = 0;
		cin>>n;
		int a[n];
		int max_ending_here = 0;
		int max_so_far = -1000000;
		for(int i = 0;i<n-1;i++){
			cin>>a[i];
			if(a[i]> max_ending_here+a[i]){
	       		max_ending_here = a[i];
			}
			else{ 
				max_ending_here = max_ending_here+a[i];
    	    	solj = i;
			} 

    	    if(max_ending_here >  max_so_far && ){
	       		soli = i;
    	    	max_so_far = max_ending_here;
    	    }
		}

		if(max_so_far<0)
			cout<<"Route "<<cont<<" has no nice parts"<<endl;
		else
			cout<<"The nicest part of route " <<cont<< " is between stops "<<soli+1<<" and "<<solj+2<<endl;
		cont++;
	}
	return 0;
}