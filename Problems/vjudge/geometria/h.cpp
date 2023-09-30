#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define x first
#define y second    
const ld pi = acos(-1);
int main(){
    int n;
    ld X,alpha,T,d,a,b;
    cin>>n>>X;
    cin>>alpha>>T>>d;
    vector<pair<ld,ld>> points(n);
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        points[i] = {a,b};
    }
    ld time = T/360.0;
    ld cone = time*alpha;
    ld grades = X/time;
    int complete = floor(grades/360.0);
    ld mod = fmod(grades,360.0);
    vector<ld> ans(n);
    // cout<<time<<endl;
    for(int i = 0;i<n;i++){
        ld distance = sqrt(points[i].x*points[i].x+points[i].y*points[i].y);
        if(isgreater(distance,d))continue;
        ld angle = acos(abs(points[i].x)/distance);
        angle= (angle*180)/pi;
        if(points[i].x<=0)angle= 180-angle;
        if(points[i].y<=0)angle= 360-angle;
        ld Tpoint = 0.0;
        if(isgreater(alpha/2.0,angle)){
            Tpoint+=time*(alpha-((alpha/2.0)-angle));
            ld ng = grades-(alpha-((alpha/2.0)-angle));
            if(ng>=0){
                int cp = floor(ng/360.0);
                Tpoint+=cone*cp;
                ld nmod = fmod(ng,360);
                ld rest = alpha-(360-nmod);
                if(rest>=0)
                    Tpoint+=time*rest;    
            }
        }
        else if(isgreater(angle,360-(alpha/2.0))){
            Tpoint+=time*((alpha/2.0)-(360-angle));
            ld ng = grades-(alpha-angle);
            if(ng>=0){
                int cp = floor(ng/360.0);
                Tpoint+=cone*cp;
                ld nmod = fmod(ng,360);
                cout<<Tpoint<<" "<<ng<<" "<<cp<<" "<<nmod<<"  "<<time<<endl;
                ld rest = nmod-angle;
                cout<<rest<<endl;
                if(rest>=0)
                    Tpoint+=time*rest;    
            }
        }
        else{
            Tpoint+=cone*complete;
            if(isgreater(0.0,mod-angle))Tpoint+=0.0;
            else Tpoint+= time*min(mod-angle,alpha);
        }
        ans[i]= Tpoint;
    }
    cout<<fixed<<setprecision(10);
    for(auto c:ans)cout<<c<<endl;
    return 0;

}
//   