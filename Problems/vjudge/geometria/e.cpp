#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
template <typename T,typename U> 
pair<T,U> operator-(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}   
int main(){
    int a,b;
    vector<pair<int,int>>points(3);
    cin>>a>>b;
    points[0] = {a,b};
    cin>>a>>b;
    points[1] = {a,b};
    cin>>a>>b;
    points[2] = {a,b};
    sort(points.begin(),points.end());
    cout<<3<<endl;
    for(int i = 0;i<3;i++){
        pair<int,int> D;
        pair<int,int> AB;
        pair<int,int> AC;
        AB = points[(0+i)%3]-points[(1+i)%3];
        AC = points[(0+i)%3]-points[(2+i)%3];
        D.first = -points[i].x+AB.x+AC.x;
        D.second = -points[i].y+AB.y+AC.y;
        cout<<-D.first<<" "<<-D.second<<endl;
    }
}