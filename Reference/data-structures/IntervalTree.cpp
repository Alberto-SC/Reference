#include <bits/stdc++.h>                                        // exclude-line
using namespace std;                                            // exclude-line
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);      // exclude-line
#define endl '\n'                                               // exclude-line

/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: Interval tree is a structure that stores segments in a efficient way,
 * allows to get all intervals that intersects with another interval  
 * Time: O(ans) where ans is the number of intervals that intersects.
 * Usage:     root = build_interval_tree(vector<recta>);
 *            query(root,R); R is an instance of recta 
*/

typedef long long int lli;
typedef long double ld;

struct recta { 
    ld x1,x2;
    int id;
    friend ostream& operator << (ostream &out, const recta&p ){
        out<<"("<<p.x1<<","<<p.x2<<", "<<p.id<<")";
        return out;
    }
};

struct central{
    ld x;
    vector<recta> x1order;
    vector<recta> x2order;
    friend ostream& operator <<(ostream &out, const central&p){
        out<<"[ ";
        for(int i = 0;i<p.x1order.size();i++){
            out<<p.x1order[i]<<" ";
        }
        out<<"]";
        return out;
    }
};

struct node {
	node *l, *r;
    central C;
	node(node *l, node *r, central C) :
		l(l), r(r),C(C) {}
};

inline bool leaf(node *x){ 
    return !x->l && !x->r;
}

node* build_interval_tree(vector<recta> &R){	
    if(R.size() == 0)return NULL;
    int n = R.size();
    int mid = (n-1)>>1;
	vector<recta> r1,r2;
    central c;
    ld x = (R[mid].x1+R[mid].x2)/2.0;
    c.x =  x;
    for(int i = 0;i<n;i++){
        if(islessequal(R[i].x1,x) && islessequal(x,R[i].x2)){
            c.x1order.push_back(R[i]);
            c.x2order.push_back(R[i]);
        }
        else if(R[i].x2<x)
            r1.push_back(R[i]);
        else 
            r2.push_back(R[i]);
    }    
    sort(c.x1order.begin(),c.x1order.end(),[&](recta a,recta b){
        return islessequal(a.x1,b.x1);
    });
    sort(c.x2order.begin(),c.x2order.end(),[&](recta a,recta b){
        return islessequal(a.x2,b.x2);
    });
	node *left = build_interval_tree(r1);
	node *right = build_interval_tree(r2);
	return new node(left,right,c);
}
set<lli> ids;

void findI(central C,recta R,bool dir){
    if(dir){
        int l = -1, r = C.x2order.size();
        while(l+1<r){
            int m = (l+r)>>1;
            if(isgreaterequal(C.x2order[m].x2,R.x1))
                r = m;
            else 
                l = m;
        }
        int n = C.x2order.size();
        for(int i = r;i<n;i++)
            ids.insert(C.x2order[i].id);        
    
    }
    else{
        int l = -1, r = C.x2order.size();
        while(l+1<r){
            int m = (l+r)>>1;
            if(islessequal(C.x1order[m].x1,R.x2))
                l = m;
            else 
                r = m;
        }        
        for(int i = l;i>=0;i--)
            ids.insert(C.x1order[i].id);
    }
}

void query(node *t, const recta& R){
    if(!t)return;
    if(isgreaterequal(t->C.x,R.x1) && islessequal(t->C.x,R.x2)){
        for(int i = 0;i<t->C.x1order.size();i++)
            ids.insert(t->C.x1order[i].id);
        query(t->l,R);
        query(t->r,R);
    }
    else if(isless(R.x2,t->C.x)){
        findI(t->C,R,0);
        query(t->l,R);
    }
    else{
        findI(t->C,R,1);
        query(t->r,R);
    }
}

// exclude-from-here
int main(){__
    lli n,x,y,a,b,q;
    cin>>n>>q;
    vector<recta> R;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        R.push_back({y-(x*0.5),y+(x*0.5),i+1});
    }
    node *root;
    root = build_interval_tree(R);
    lli p = 0;
    for(int i = 0;i<q;i++){
        cin>>a>>b;
        x = -1-((p+a)%mod);
        y = (p+b)%mod;
        ld r = y-(x*0.5);
        ld l = y+(x*0.5);
        ids.clear();
        recta R = {(ld)l,(ld)r,0};
        query(root,R);
        int cont = 0;
        lli ans = 0;
        for(auto c:ids){
            c%=mod;
            lli z = mod_pow(5782344,cont++);
            (c*=z)%=mod;
            (ans+=c)%=mod;
        }
        ans%=mod;
        p = ans;
        cout<<ans<<endl;
    }
    return 0;
}

