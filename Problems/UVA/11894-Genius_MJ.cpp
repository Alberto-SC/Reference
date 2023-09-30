#include <bits/stdc++.h>
using namespace std;
typedef long double Doubel;
const Double INF = 1ll << 60;
const Double ERROR = 1e-9;
#define EQ(a, b) (fabs((a) - (b)) < ERROR)
struct Punto{
	double x,y;
	Punto(): x(),y(){}
	Punto(double X,double Y):x(X),y(Y) {}
	Punto(Punto P,Puntp Q){*this = p-q;}

	bool operator<(const Punto& q){
		if(!EQ(x,q.X))return x<q.x;
		return EQ(y,q.y)? false:y<q.y; 
	}
	bool operator=(const Punto& q){
		return EQ(x,q.x)  &&  EQ(y,q.y);
	}
	Punto operator+(const Punto &q){
		return Punto(x+q.x,y+q.y);
	}
	Punto rot90() const { return Punto(-y, x); }
    Punto translate(Punto p,Punto q){
			double vx = q.x - p.x;
			double vy = q.y - p.y;
			return Punto(x + vx, y + vy);
	}


};

inline int isInsideBox(const Punto p, const Punto lowerLeft, const Punto upperRight)
{
	if (p.x > lowerLeft.x and p.y > lowerLeft.y and p.x < upperRight.x and p.y < upperRight.y)
		return 1;

	if (p.x < lowerLeft.x or p.y < lowerLeft.y or p.x > upperRight.x or p.y > upperRight.y)
		return 0;

	return -1;
}


vector<Punto> M,H;
bool sol(){
	return true; 
	return false;
}
int main(){
	int t,N;
	double x,y;
	cin>>t; 
	Punto minm(10000,10000);
	Punto ori(10000,10000);
	bool H[2001][2001];
	bool yes;
	const Punto upperRight(1000, 1000);
	const Punto lowerLeft(-1000, -1000);
	while(t--){
		cin>>N;
		M.clear();
		memset(socket, false, sizeof socket);
		for(int i = 0;i<N;i++){
			cin>>x>>Y;
			M.push_back(Punto(x,y));
			minm = min(minm,M[i]);
		}
		for(int i = 0;i<N;i++){
			cin>>x>>y;
			Punto s(x,y);
			ori = min(ori,s);
			H[x + 1000][y + 1000] = true;
		}
		for(int i = 0;i<4;i++){
			if( i >0){
				minm.x =100000;
				minm.y=100000;
				for(int j = 0;j<N;j++){
					M[j].rot90();
					minm = min(minm,M[i]);
				}
			}
			yes = true;
			Punto des(ori,minm);
			for(int j = 0;j<N;j++){
				Punto p = M[j] +des;
				if(isInsideBox(p,lowerLeft,upperRight) == 0 or not H[p.x+1000][p.y+1000]){
					yes = false;
					break;
				} 
			}
			if(yes)break;
		}
		if(yes)
			cout<<"MATCHED";
		else 
			cout<<"NOT MATCHED";
	}
	return 0;
}