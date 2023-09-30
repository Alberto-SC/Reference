#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> le;
long long res1 = -1,res2 = -1;
long long  count(int ans,int n){
  long long tmp = 0,t=0;
  bool pv = false;
  int i=0,j=0;
  while(i<n){
    if(j+1 < n and le[j+1]-le[i] <= ans){
      j++;
      t++;
    }else{
      tmp += t;
      t--;
      i++;
    }
  }

  return tmp;
}
void solve(int ans,int kth,int n){
  long long tmp = 0,t=0;
  
  int i=0,j=0;
  while(i<n){
    if(j+1 < n and le[j+1]-le[i] <= ans){
      if(le[j+1]-le[i] == ans){
        t++;
        if(t==kth){
          cout<<le[i]<< " " << le[j+1] << endl;return;
        }
      }

      j++;
    }else{
      i++;
    }
  }

}
int main(){
	long long n,k,ni;
	cin>>n>>k;

	while(n != 0 && k != 0){
		le.clear();
		for(int i = 0 ; i<n;i++){
			cin>>ni;
			le.push_back(ni);
		}
		sort(le.begin(),le.end());
		long long l = 0, r =  1000000005,mid;
		//cout<<endl;
		while(l <  r){
			mid = (l+r)/2;
			long long  c = count(mid,n);
			//cout<<mid<<"  "<<c<<endl;
			if(c >= k) r = mid;
			else l = mid+1;
		}
		//cout<<l<<endl;
		long long  kth = k - count(l-1,n);
		//cout<<kth<<endl;
    	solve(l,kth,n);
		cin>>n>>k;
	}


	return 0;
}