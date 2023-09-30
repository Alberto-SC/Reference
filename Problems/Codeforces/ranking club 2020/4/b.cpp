#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
bool comp(pair<pair<int,int>,int> A ,pair<pair<int,int>,int> B){
    return A.first.first<B.first.first;
}
double getdistance(pair<int,int> A,int x){
    double ans;
    double x1 = A.first*1.0,y1 = A.second*1.0,x2 = x*1.0;
    ans = (x1-x2)*(x1-x2);
    ans+= y1*y1;
    ans = sqrt(ans);
    return ans;
}
int main(){
    int n,x,r,m,y;
    cin>>n;
    vector<pair<pair<int,int>,int>> circles(n);
    for(int i = 0;i<n;i++){cin>>x>>r;circles[i] = {{x,r},i};}
    cin>>m;
    sort(circles.begin(),circles.end(),comp);
    vector<int> ans(n,-1);
    for(int i = 0;i<m;i++){
        cin>>x>>y;
        pair<int,int> point ={x,y};
        pair<int,int> search = {x,0};
        int index =  lower_bound(circles.begin(),circles.end(),make_pair(search,0))-circles.begin();
        int xclosest = circles[index].first.first;
        double distance1 = 0,distance2;
        if(index == n){
            distance1 = getdistance(point,circles[index-1].first.first);
            if(isgreaterequal(circles[index-1].first.second*1.0,distance1) && ans[circles[index-1].second] ==-1)ans[circles[index-1].second] = i+1;
        } 
        else if(index == 0|| x == xclosest){
            distance1 = getdistance(point,circles[index].first.first);
            if(isgreaterequal(circles[index].first.second*1.0,distance1) && ans[circles[index].second] ==-1)ans[circles[index].second] = i+1;
        }
        else{
            distance1 = getdistance(point,circles[index].first.first);
            if(isgreaterequal(circles[index].first.second*1.0,distance1) && ans[circles[index].second] ==-1)ans[circles[index].second] = i+1;  
            distance2 = getdistance(point,circles[index-1].first.first);
            if(isgreaterequal(circles[index-1].first.second*1.0,distance2) && ans[circles[index-1].second] ==-1)ans[circles[index-1].second] = i+1;    
        }
    }
    int cont =0;
    for(int i = 0;i<n;i++){
        if(ans[i]!= -1)cont++;
    }
    cout<<cont<<endl;
    for(auto c:ans)cout<<c<<" ";
    return 0;
}