#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


lli wf(lli x1,lli y1,lli x2,lli y2){
    lli size = ((x2-x1)+1)*((y2-y1)+1);
    if((x1+y1)%2 == 0)return ceil(size/2.0);
    else return size-ceil(size/2.0);

}
int main(){
    lli t,n,m,x1,x2,y1,y2,a1,a2,b1,b2,ax1,ax2,by1,by2;
    cin>>t;
    while(t--){
        cin>>n>>m;
        lli w = ceil((n*m)/2.0);
        lli b = (n*m)-w;
        cin>>x1>>y1>>x2>>y2;
        cin>>a1>>b1>>a2>>b2; 
        ax1 = max(x1,a1);
        ax2 = min(x2,a2);
        by1 = max(b1,y1);
        by2 = min(b2,y2);
        lli size = ((x2-x1)+1)*((y2-y1)+1);
        lli size2 = ((a2-a1)+1)*((b2-b1)+1);
        // cout<<size<<" "<<size2<<endl;
        lli w1 = wf(x1,y1,x2,y2);
        lli w2 = wf(a1,b1,a2,b2);
        w+=size-w1,b-=size-w1;
        w-=w2,b+=w2;
        if(by1>by2 || ax1>ax2){
            cout<<w<<" "<<b<<endl;
        } 
        else {
            lli sizei = (ax2-ax1+1)*(by2-by1+1);
            lli bl = sizei-wf(ax1,by1,ax2,by2);
            w-=bl,b+=bl;
            cout<<w<<" "<<b<<endl;
        }
    }
    return 0;
}