#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
#define oo 1000000000


struct point { 
    int x, y,id;
    bool operator < (const point A){return x<A.x;}
    friend ostream& operator << (ostream &out, const point&p ){
        out<<"("<<p.x<<","<<p.y<<") "<<id<<endl;
        return out;
    }
};
struct region { 
    int xlo, xhi, ylo, yhi; 
    friend ostream& operator << (ostream &out, const region&p ){
        out<<"("<<p.xlo<<","<<p.ylo<<","<<p.xhi<<","<<p.yhi<<")";
        return out;
    }
};

struct node {
	point p;
	node *l, *r;
	region R;
	node( point p, node *l, node *r, int xlo, int xhi, int ylo, int yhi ) :
		p(p), l(l), r(r), R({xlo, xhi, ylo, yhi }) {}
}*root;

inline bool leaf( node *x ) { return !x->l && !x->r; }
inline bool less_than( const point& a, const point &b, bool byX ) {
	return byX ? a.x < b.x : a.y < b.y;
}

void partition( vector<point> &a, int lo, int hi, const int& k, bool byX ) {
	int l = lo, r = hi - 1, mid = ( lo + hi ) >> 1;
	if (less_than(a[mid],a[lo],byX)) swap(a[mid],a[lo]);
	if (less_than(a[hi],a[lo],byX)) swap(a[hi],a[lo]);
	if (less_than(a[hi],a[mid],byX)) swap(a[hi],a[mid]);
	if (hi - lo + 1 <= 3 ) return;
	swap(a[mid],a[hi-1]);
	point pivot = a[hi-1];
	for (;;) {
		while (less_than(a[++l],pivot,byX));
		while (less_than(pivot,a[--r],byX));
		if (l < r) swap(a[l],a[r]);
		else break;
	}
	swap(a[l],a[hi-1]);
	if (k<l) partition(a,lo,l-1,k,byX);
	if (k>l) partition(a,l+1,hi,k,byX);
}

node* build_kd_tree(vector<point> p, int len, int depth,int xlo, int xhi, int ylo, int yhi){
	if (len == 1)
		return new node(p[0],NULL,NULL, p[0].x, p[0].x, p[0].y, p[0].y );
	int mid = (len-1)/2;
	partition(p,0,len-1,mid,!(depth&1));
	vector<point> p1(len), p2(len);
	int c1 = 0, c2 = 0;
	for (int i = 0;i<=mid;i++) p1[c1++] = p[i];
	for (int i = mid+1;i<len;i++) p2[c2++] = p[i];
	int xlo1 = xlo, xhi1 = xhi, ylo1 = ylo, yhi1 = yhi,xlo2 = xlo, xhi2 = xhi, ylo2 = ylo, yhi2 = yhi;
	if (!(depth&1))
		xhi1 = p[mid].x, xlo2 = p[mid].x + 1;
	else
        yhi1 = p[mid].y, ylo2 = p[mid].y + 1;
	node *left = build_kd_tree(p1,mid+1,depth+1,xlo1, xhi1, ylo1, yhi1);
	node *right = build_kd_tree(p2,len-mid-1,depth+1,xlo2, xhi2, ylo2, yhi2);
	return new node(p[mid],left, right, xlo, xhi, ylo, yhi);
}
bool flag = false;
int idx = -1;
void report( node *t ) {
	if (leaf(t)){
        // cout<<t->p<<" ";
        idx = t->p->id;
    }
	else{
		report(t->l);
		report(t->r);
	}
}
void print(node *root){
    if(!root)return;
    print(root->l);
    cout<<root->p<<" "<<root->R<<endl;
    print(root->r);
}


bool contained( const region& a, const region& b ) {
	return (b.xlo <= a.xlo && a.xlo <= b.xhi &&
			b.xlo <= a.xhi && a.xhi <= b.xhi &&
			b.ylo <= a.ylo && a.ylo <= b.yhi &&
			b.ylo <= a.yhi && a.yhi <= b.yhi );
}

bool intersect( const region& a, const region& b ) {
	bool okX = ( ( a.xlo <= b.xlo && b.xlo <= a.xhi ) ||
                 ( a.xlo <= b.xhi && b.xhi <= a.xhi ) ||
                 ( b.xlo <= a.xlo && a.xhi <= b.xhi ));
	bool okY = ( ( a.ylo <= b.ylo && b.ylo <= a.yhi ) ||
                 ( a.ylo <= b.yhi && b.yhi <= a.yhi ) ||
                 ( b.ylo <= a.ylo && a.yhi <= b.yhi ));
	return okX && okY;
}

void query(node *t, const region& R ) {
    if(contained(t->l->R,R)){
        report(t->l);
        return ;
    }
    else if(intersect(t->l->R,R))
        query(t->l,R);
    if(contained(t->r->R,R)){
        report(t->r);
        return ;
    }
    else if(intersect(t->r->R,R))
        query(t->r,R);
}

int main() {
    int n,q,xlo, ylo,xhi, yhi,w,h;
    cin>>n;
    vector<point> points(n);
    vector<pair<int,int>> rect;
    for(int i = 0;i<n;i++){
        cin>>h>>w;
        rect.push_back({h,w});
        points.push_back({h,w,i});
        points.push_back({w,h,i});
    }
	root = build_kd_tree(points,n,0,-oo,oo,-oo,oo);
	for(int i = 0;i<n;i++){
        region R = {0,rect[i].first,0,rect[i].second[]}
        cin>>xlo>>ylo>>xhi>>yhi;
		region R ={xlo,xhi,ylo,yhi};
		query(root,R);
        cout<<endl;
	}
	return 0;
}

