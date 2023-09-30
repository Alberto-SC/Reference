#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct rect{
    int x0,y0,x1,y1;
    bool operator >=(const rect b){
        return (b.x0 >= x0 && b.y0>=y0 && b.x1 <=x1 && b.y1<=y1);
    }
    friend ostream& operator <<(ostream &out,const rect m){
        out<<m.x0<<" "<<m.y0<<" "<<m.x1<<" "<<m.y1<<endl;
        return out; 
    }
};
signed main(){__
	int t= 1,n,x1,x2,y1,y2;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        rect r1 = {x1,y1,x2,y2};
        cin>>x1>>y1>>x2>>y2;
        rect r2 = {x1,y1,x2,y2};
        cin>>x1>>y1>>x2>>y2;
        rect r3 = {x1,y1,x2,y2};
        if(r2 >=r1 || r3>=r1)cout<<"NO"<<endl;
        else {
            bool flag = true;
            if(r2.y0>r3.y0)swap(r2,r3);
            if(r2.y1>=r3.y0){
                rect r4 ={max(r2.x0,r3.x0),r2.y0,min(r2.x1,r3.x1),r3.y1};
                // cout<<r4<<endl;
                if(r4 >= r1)flag = false;
            }
            if(r2.x0>r3.x0)swap(r2,r3);
            if(r3.x0 <= r2.x1){
                rect r4 = {r2.x0,max(r2.y0,r3.y0),r3.x1,min(r2.y1,r3.y1)};
                // cout<<r4<<endl;
                if(r4 >=r1)flag = false;
            }
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}  
