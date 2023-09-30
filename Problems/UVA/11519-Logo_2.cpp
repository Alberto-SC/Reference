#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
const double ERROR = 1e-2;
int main(){
	string a,p;
	int t,n,phi,anglem;
	double  r ,an,x,y;
	cin>>t;
	vector<pair<string ,string>> inst;
	while(t--){
		cin>>n;
		phi = 0;
		x = 0;
		y = 0;
		inst.clear();
		bool theta = false,back = false;
		for(int i = 0;i<n;i++){
			cin>>a>>p;
			if(theta)
				inst.push_back(make_pair(a,p));
			else{
			if(a[0] == 'f'){
				if(p[0] == '?'){
					anglem = phi;
					continue;
				} 
				else{	
				r  = stoi(p);
				x += r*cos(phi*(M_PI/180));
				y += r*sin(phi*(M_PI/180));
				}
			}
			else if(a[0] == 'b'){	
				if(p[0] == '?'){
					anglem = phi;
					back = true;
					continue;
				}
				else{
				r = stoi(p);	
				x -= r*cos(phi*(M_PI/180));
				y -= r*sin(phi*(M_PI/180));
				}
			}
			else if(a[0] == 'l'){
			 	if(p[0] == '?'){
			 		theta = true;
			 		inst.push_back(make_pair(a,p));
			 		continue;
			 	}
			 	else{	
			 		an = stoi(p);
			 		phi+=an;
			 		phi = phi%360;
			 	}
			}
			else if(a[0] == 'r'){
				if(p[0] == '?'){
					theta = true;
					inst.push_back(make_pair(a,p));
					continue;
				}
				else{

					an = stoi(p);
			    	phi-=an;
					if(phi<0) phi = 360+phi;
				}
			}
			}
		}
		if(theta){
			int i,cphi = phi;
			double cx = x,cy = y;
			for(i = 0;i<360;i++){
				char z[40];
				//itoa(i,z,10);
				inst[0].second = to_string(i);
				x = cx;
				y = cy;
				phi = cphi;
				for(int j = 0;j<inst.size();j++){
					a = inst[j].first;
					r = stoi(inst[j].second);
					an = stoi(inst[j].second);
					if(a[0] == 'f'){
						x += r*cos(phi*(M_PI/180));
						y += r*sin(phi*(M_PI/180));	
					}
					else if(a[0] == 'b'){	
						x -= r*cos(phi*(M_PI/180));
						y -= r*sin(phi*(M_PI/180));	
					}
					else if(a[0] == 'l'){
						phi +=an;
			 			phi = phi%360;
					}
					else if(a[0] == 'r'){
			    		phi -=an;
						if(phi<0) phi = 360+phi;
					}
				}
				if(fabs((x) - (0)) < ERROR && fabs((y) - (0)) < ERROR)
					break;
				else 
					continue;
			}
			cout<<i<<endl;
		}
		else{
			if(!back)
				r = -x/cos(anglem*(M_PI/180));
			else
				r = x/cos(anglem*(M_PI/180));	
			cout<<fabs(round(r))<<endl;
		}
	}

	return 0;
}