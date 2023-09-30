#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define ld long double

struct point{
  ld x,y;
  point():x(0),y(0){}
  point(ld x,ld y):x(x),y(y){}

  point operator +(const point b){return point(x+b.x,y+b.y);}
  point operator -(const point b){return point(x-b.x,y-b.y);}
  ld dot(const point p){return x*p.x,y*p.y;}
  ld cross(const point p){return x*p.y-y*p.x;}
  int operator%(point p){return x*p.y-y*p.x;}
  bool in(point p, point q){return (q-p)%(*this-p)==0;}
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

int getC3(int n){
  return (n*(n-1)*(n-2))/6;
}

int getC4(int n){
  return (n*(n-1)*(n-2)*(n-3))/24;
}

signed main(){__
  int n;
  cin>>n;
  vector<point> p(n);
  for(int i = 0;i<n;i++){
    cin>>p[i];
  }

  int total = getC4(n);

  map<pair<int,int>,map<int,set<int>>> mp;
  for(int i = 0;i<n;i++){
    for(int j = i+1;j<n;j++){
      for(int k = j+1;k<n;k++){
        int A,B,C;
              
        point a = p[i];
        point b = p[j];
    
        A = a.y-b.y;
        B = a.x-b.x;
        int gcd = __gcd(A,B);
        A/=gcd;
        B/=gcd;
        C = (a.x*A) - (a.y*B);
      
        mp[{A,B}][C].insert(i);
        mp[{A,B}][C].insert(j);
      }
    }
  }
  for(auto c:mp){
    for(auto d:c.second){
      int sz = d.second.size();
      if(sz>=3){
        total-=getC3(sz)*(n-sz);
      }
      if(sz>=3){
        total-=getC4(sz);
      }
    }
  }
  cout<<total<<endl;
  return 0;
}

