#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int main(){
	int n,e,c =1;;
	cin>>n;
	stack<int> p;
	cin>>e;
	p.push(e);
	for(int i = 1;i<n;i++){
		cin>>e;
		if(e == p.top()){
			while(p.top() == pow(e,c)){
				p.pop();
				c++;
			}
			p.push(pow(e,c));
		} 
		else p.push(e);  
	}
	cout<<p.size()<<"\n";
	while(!p.empty()){
		cout<<p.top()<<"\n";
		p.pop();
	}

}