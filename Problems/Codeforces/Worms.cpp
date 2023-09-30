#include <iostream>
#include <vector>

using namespace std;
int main(){
	int n,j,nw,nj,mid;
	vector<int> p;
	cin>>n;
	cin>>nw;
	vector<int> res;
	p.push_back(nw);
	for(int i = 1;i<n;i++){
		cin>>nw;
		p.push_back(p[i-1]+nw);
	}
	cin>>j;
	res.resize(j);
	for(int i = 0;i<j;i++){
		cin>>nj;
		int l = 0,r = n-1;
		while(l<=r){
			mid = (r+l)/2;
			if(p[mid]< nj)
				l = mid+1;
			else {	
				r = mid-1;
				res[i] =  mid;
			}
		}
	}
	for(int i = 0;i<j;i++){
		cout<<res[i]+1<<endl;
	}


}