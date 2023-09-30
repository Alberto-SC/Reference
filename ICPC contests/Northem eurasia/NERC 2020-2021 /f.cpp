#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
typedef long double ld;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,ux,uy,vx,vy;
    cin>>t;
    while(t--){
        cin>>n;
        map<lli,int> grades;
        cout<<fixed<<setprecision(6);
        for(int i = 0;i<n;i++){
            cin>>ux>>uy>>vx>>vy;
            ld angle;
            if(ux == vx){
                if(vy>uy)angle = 90;
                else angle = 270;
            }
            else if(uy == vy){
                if(vx>ux)angle = 0;
                else angle = 180;
            }
            else {
                angle = (atan((ld)(vy-uy)/(vx-ux))*180)/acos(-1);
            }
            vy-=uy;
            vx-=ux;
            if(vy<0 && vx<0)angle+= 180;
            else if(vy<0 && vx>0)angle = 360+angle;
            else if(vx<0 && vy>0)angle = 180+angle;
            grades[angle*10000000000ll]++;
            // cout<<angle<<endl;
        }
        lli ans = 0;
        for(auto c:grades){
            // cout<<c.first<<" "<<c.second<<" "<<c.first+(180*10000000000ll)<<endl;
            if(grades.count(c.first+(180*10000000000ll))){
                // cout<<"HI"<<endl;
                ans+= ((lli)c.second)*grades[c.first+(180*10000000000ll)];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

