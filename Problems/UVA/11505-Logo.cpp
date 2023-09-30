#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
	string a,b;
	int t,n,angle;
	double  r,xo ,yo ,an,x,y;
	pair<int,int> acc;
	cin>>t;
	while(t--){
		cin>>n;
		angle = 0;
		x = 0;
		y = 0;
		for(int i = 0;i<n;i++){
			cin>>a;
			if(a[0] == 'f'){
				cin>>r;
				xo = r*cos(angle*(M_PI/180));
				x = x+xo;
				yo = r*sin(angle*(M_PI/180));
				y = y+yo;
			}
			else if(a[0] == 'b'){	
				cin>>r;
				xo = r*cos(angle*(M_PI/180));
				x = x-xo;
				yo = r*sin(angle*(M_PI/180));
				y = y-yo;
			}
			else if(a[0] == 'l'){
				cin>>an;
			 	angle+=an;
			 	angle = angle%360;
			}
			else if(a[0] == 'r'){
				cin>>an;
			    angle-=an;
				if(angle<0) angle = 360+angle;
			}
		}
		/*for(int i = 0;i<points.size();i++){
			cout<<"("<<points[i].x<<","<<points[i].y<<")"<<endl;
			
		}*/
		printf("%.lf\n", sqrt(x*x+y*y));
	}

	return 0;
}