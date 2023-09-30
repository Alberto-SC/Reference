#include <iostream>
#include <string>
using namespace std;


int main(){
	int t,n,g,d,j = 1;
	string c;
	cin>>t;
	vector<pair<int,int>>p;
	p.push_back(mañe_pair(0,0));
	for(int i = 0;i<t;i++){
		cin>>n;
		for(int i = 0;i<n;i++){
			cin>>c;
			if(c == "fd"){				
				cin>>d;
				p.push_back(make_pair(p[j-1].first +d,p[j-1].second));
			}
		}
	}
	return 0;

}