#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t,n,nc,c,ulti,cont = 1,r,l,mid,res;
	cin>>t;
	vector <int> vacas;
	for(int i = 0;i<t;i++){
		cin>>n>>nc;
		vacas.clear();
		for(int j = 0;j<n;j++){
			cin>>c;
			vacas.push_back(c);
		}
		sort(vacas.begin(),vacas.end());
		r = vacas[vacas.size()-1]-vacas[0];
		l = 0;
		while(l<=r){
			mid = (l+r)/2; 
			cont = 1;
			ulti = vacas[0];
			for(int x  = 1;x<n; x++){
				if(mid > vacas[x]-ulti)
					continue;
				ulti = vacas[x];
				cont++;
			}
			if(cont >= nc){
				l = mid +1;
				res = mid;
			}	
			else 
				r = mid -1;
			
		}
		cout<<res<<endl;
	}

}