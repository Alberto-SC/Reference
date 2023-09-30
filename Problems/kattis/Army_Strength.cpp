#include <iostream>
#include <queue> 
using namespace std;
	
int main(){
	int t,nm,ng,a;
	cin>>t;
	priority_queue<int> pq1;
	priority_queue<int> pq2;

	for(int i = 0;i<t;i++){
		cin>>nm>>ng;
		for(int i = 0;i<nm;i++){
			cin>>a;
			pq1.push(-a);
		}
		for(int i =0; i<ng;i++){
			cin>>a;
			pq2.push(-a);
		}
		while(!pq1.empty()&&!pq2.empty()){
			if(pq1.top()>pq2.top())
				pq1.pop();
			else
				pq2.pop();
		}
		if(pq1.empty()) cout<<"MechaGodzilla"<<endl;
		else if(pq2.empty()) cout<<"Godzilla"<<endl;
		else cout<<"uncertain"<<endl;
	}
}