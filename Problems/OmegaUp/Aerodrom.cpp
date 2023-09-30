#include <iostream>
#include <vector>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	vector<int> t;
	long long  n,m,ti,l = 0,r,max = -1000,s,res = 0,mid;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>ti;
		if(ti  >max) max = ti;
		t.push_back(ti);
	}
	r = max*m;
	while (l <= r){
        mid = (l + r)/2;
        res = 0;
        for(int i = 0;i<n;i++) 	res += mid/t[i];
        if (res < m)
            l = mid + 1;
        else{	
            r = mid - 1;
        	s = mid;
        }
    }
    cout<<s;
    return 0;
}