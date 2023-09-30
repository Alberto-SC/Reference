#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
typedef long long int lli;

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b

struct point{
	ld x,y;
	
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y);}
	point operator*(const ld & k) const{return point(x * k, y * k);}
	point operator/(const ld & k) const{return point(x / k, y / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const ld & p){*this = *this * p; return *this;}
	point operator/=(const ld & p){*this = *this / p; return *this;}

	ld cross(const point &p) const{
		return x*p.y - y*p.x;
	}
	ld dot(const point &p) const{
		return x*p.x + y*p.y;
	}
};

bool pointInLine(const point &a, const point &v, const point &p){
	return eq((p-a).cross(v), 0);
}

bool pointInSegment(const point &a, const point &b, const point &p){
	return pointInLine(a, b-a, p) && leq((a-p).dot(b-p), 0);
}

int bfs(int start, int end, vector<vector<int>> &graph){
	queue<pair<int,int>> q;
	vector<bool> visited(graph.size(), false);
	q.push(make_pair(start,0));
	visited[start] = true;

	while(!q.empty()){
		auto act = q.front();
		q.pop();
		if(act.first == end){
			return act.second;
		}

		for(auto n:graph[act.first]){
			if(!visited[n]){
				q.push(make_pair(n,act.second+1));
				visited[n] = true;
			}
		}
	}

	return -1;	
}

int main(){
	int n; cin >> n;
	vector<point> t1(n),t2(n);

	for(auto &p:t1) cin >> p.x >> p.y;
	for(auto &p:t2) cin >> p.x >> p.y;

	vector<vector<int>> graph(n);
	for(int i=0; i<(n-1); i++){
		for(int j=i+1; j<n; j++){
			bool isFree = true;

			for(int k=0; k<n; k++){
				if(k != i && k != j){
					if(pointInSegment(t1[i], t1[j], t1[k])){
						isFree = false;
					}
				}
			}

			for(int k=0; k<n; k++){
				if(pointInSegment(t1[i], t1[j], t2[k])){
					isFree = false;
				}
			}

			if(isFree){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	cout << bfs(0, n-1, graph) << endl;
	return 0;
}