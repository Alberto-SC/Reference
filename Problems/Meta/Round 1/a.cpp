#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second 
typedef long long int lli;
const lli mod = 1000000007;
int main(){
    lli t,n,k,w,al,bl,cl,dl,ah,bh,ch,dh;
    cin>>t;
    while(t--){
        cin>>n>>k>>w;
        vector<pair<int,int>> rect(k);
        for(int i = 0;i<k;i++)
            cin>>rect[i].x;
        
        cin>>al>>bl>>cl>>dl;
        for(int i = 0;i<k;i++)
            cin>>rect[i].y;

        cin>>ah>>bh>>ch>>dh;
        for(int i = k;i<n;i++){
            lli xl,xh;
            xl = al*rect[i-2].x;
            xl%=dl;
            xl+= bl*rect[i-1].x;
            xl%=dl;
            xl+= cl;
            xl%=dl;
            xl++;
            xl%=dl;

            xh= ah*rect[i-2].y;
            xh%=dh;
            xh+= bh*rect[i-1].y;
            xh%=dh;
            xh+= ch;
            xh%=dh;
            xh++;
            xh%=dh;
            rect.push_back({xl,xh});
        }
        for(auto c :rect)cout<<c.x<<" "<<c.y<<endl;
        lli p= 1;
        lli lastx = 0,un;
        for(int i = 0;i<n;i++){
            if(rect[i].x<lastx){
                
            }
            else {
                un+= w*rect[i].y;
                lastx= rect[i].x +w;
            }
        }
    }

    return 0;
}