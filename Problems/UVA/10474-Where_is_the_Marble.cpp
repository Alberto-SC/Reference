#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binaria(int e, vector<int> ma){
    int l = 0 ,r= ma.size(), res =-1;

    while (l <= r){
        int m = l + (r-l)/2;
        if (ma[m] < e)
            l = m + 1;
        else{	
            r = m - 1;
        	res = m;
        }
    }
    return res;
}

int main (){
	int n,nq,m,q,t = 1;
	do{
		cin>>n>>nq;
		if(n == 0 && nq == 0)break;
		vector<int> ma;
		for(int i = 0; i<n;i++){
			cin>> m;
			ma.push_back(m);
		}
		sort(ma.begin(), ma.begin()+n);

		cout<<"CASE# "<<t<<":"<<endl;
		t++;
		for(int i = 0;i<nq; i++){
			cin>>q;
			int r = binaria(q,ma);
			if(ma[r] == q)
				cout<<q<<" found at "<<r+1<<endl;
			else 
				cout<<q<<" not found"<<endl;
		}
	ma.clear();
	}while(n != 0 && nq != 0);
}