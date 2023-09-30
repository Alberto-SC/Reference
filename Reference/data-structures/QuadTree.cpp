#include <bits/stdc++.h>                                        // exclude-line
using namespace std;                                            // exclude-line
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);      // exclude-line
#define int long long                                           // exclude-line 
#define endl '\n'                                               // exclude-line

/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: A divide and conquer structure that divides a plane in fou sections to 
 * answer efficienly queries like how many points are inside of a rectangle
 * Time: O(n \log N).
 * Status: No tested
 * Usage:     node* head = new node(range(0,MAXN,0,MAXN)); 
 *            count(range(S[i].x,MAXN-S[i].x,S[i].y,MAXN-S[i].y),head); Range is an structure for a rectangle 
 */

struct point{
    int x,y;
    point(int _x,int _y):x(_x),y(_y){}
};
int capacity = 4;
struct range{
    int x,y,w,h; // w is width and h is height,x and y are the left upper corner 

    range(int _x,int _w,int _y,int _h):x(_x),y(_y),w(_w),h(_h){}
    bool contains(point p){
        if( p.x >= x &&  
            p.x <= x + w && 
            p.y >= y &&
            p.y <= y + h)
            return true;
        return false;
    }
    bool intersects(range R){
        return !(R.x > x+w ||
                 R.x+R.w < x   ||
                 R.y > y+h ||
                 R.y+R.h < y
            ); 
    }
};

struct node{
    range boundary;
    node(range bound):boundary(bound){}
    bool divided = false;
    vector<point> P;
    node *nw = NULL,*ne = NULL,*sw = NULL,*se = NULL;
    void divide(){
        divided = true;
        nw = new node(range(0,boundary.w/2,boundary.h/2,boundary.h/2));
        ne = new node(range(boundary.w/2,boundary.w/2,boundary.h/2,boundary.h/2)); 
        sw = new node(range(0,boundary.w/2,0,boundary.h/2)); 
        se = new node(range(boundary.w,boundary.w/2,0,boundary.h/2)); 
    }
};
int MAXN = 65536/4;



bool insert(point p,node *N){
    if(!N->boundary.contains(p))return false;
    if(!N->P.size()<capacity){
        N->P.push_back(p);
        return true;
    }
    else{
        if(!N->divided)N->divide();
        if(insert(p,N->nw))return true;
        if(insert(p,N->ne))return true;
        if(insert(p,N->sw))return true;
        if(insert(p,N->se))return true;
    }
    return true;
}

int count (range R,node *N){
    int ans = 0;
    if(!N->boundary.intersects(R))return 0; 
    for(auto p:N->P){
        if(R.contains(p))ans++;
    }
    if(N->divided){
        ans+=count(R,N->nw);
        ans+=count(R,N->ne);
        ans+=count(R,N->sw);
        ans+=count(R,N->se);
    }
    return ans;
}


int main(){
    int n,x,y;
    cin>>n;
    vector<point> S;
    node* head = new node(range(0,MAXN,0,MAXN)); 
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        S.push_back({x,y});
        insert(point(x,y),head);
    }
    vector<int> ans;
    cout<<endl;
    for(int i = 0;i<n;i++){
        if(count(range(S[i].x,MAXN-S[i].x,S[i].y,MAXN-S[i].y),head)-count(range(S[i].x,0,S[i].y,0),head)==0)ans.push_back(i+1);
    }
    
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    
    return 0;
}