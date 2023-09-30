#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z,x1,y1,z1;
	cin>>x>>y>>z;
	cin>>x1>>y1>>z1;
	vector<int> a(6);
	for(auto &c:a)cin>>c;
	int ans = 0;
	if(x>x1)ans+=a[5];
	else if(x<0)ans+=a[4];
	if(y>y1)ans+=a[1];
	else if(y<0)ans+=a[0];
	if(z>z1)ans+=a[3];
	else if(z<0)ans+=a[2];
	cout<<ans<<endl;
	return 0;
}

