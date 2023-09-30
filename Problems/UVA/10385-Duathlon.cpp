#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>  
using namespace std;

int main(){
	int n,nc,min,mid,rs,t,tc,midk,maxdif,dif;
	bool yes;
	double r,k,rr,rk;
	vector<pair<int,int>> sp;
	while(cin>>n>>nc){
		sp.clear();
		maxdif = -100;
		yes = false;
		for(int i = 0;i<nc;i++){
			cin>>r>>k;
			r = r*1000;
			k = k*1000;
			sp.push_back(make_pair(r,k));
		}
		for(mid = 0;mid<=n*1000;mid++){
			min = 1000000;
			midk = (n*1000)-mid;
			//cout<<mid<<" "<<midk<<endl;
			for(int x = 0;x<nc-1;x++){
				t = ((mid*3600)/sp[x].first) + ((midk*3600)/sp[x].second);  
				if(t < min) min = t; 
			}
			//cout<< min<<endl;
			tc = ((mid*3600)/sp[sp.size()-1].first) + ((midk*3600)/sp[sp.size()-1].second);
			if(tc <= min){
				dif = min-tc;
				if(dif>maxdif+1){
					//cout<<min<<" "<<tc<<" "<<mid<<endl;
					maxdif= dif;	
					yes = true;
					rr = mid/1000.0;
					rk = midk/1000.0;
				}
			}
		}
		cout << std::fixed;
		cout << std::setprecision(2);
		
		if(yes)
		cout<<"The cheater can win by "<<maxdif<<" seconds with r = "<<rr<<"km and k = "<<rk<<"km."<<endl;
		else 
		cout<<"The cheater cannot win."<<endl;
	}

	
	

}