#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct point{
    lli x,y;
    bool operator <(const point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    point operator-(){return{-x,-y};}
    point operator+(const point&p){return{x+p.x,y+p.y};}
    point operator-(const point&p){return{x-p.x,y-p.y};}
    friend istream &operator>>(istream &is, point&a){
        is>>a.x>>a.y;
        return is;
    }
};
set<point> pointsS;
vector<point> points;
bool Si(point vec){
    for(point &p:points){
        if(!pointsS.count(p+vec) && !pointsS.count(p-vec)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,x,y;
    cin>>n;
    points.resize(n);
    for(point &p:points)cin>>p;
    for(point p:points)pointsS.insert(p);
    set<point> sol;
    for(int i=1; i<n; ++i){
        point vec=points[i]-points[0];
        if(Si(vec)){
            if(vec.x<0)vec=-vec;
            if(vec.x==0)vec.y=abs(vec.y);
            sol.insert(vec);
        }
    }
    cout<<sol.size()*2<<endl;
    return 0;
}