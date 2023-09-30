#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x1,x2,y1,y2,w,h,W,H;
    cin>>t;
    while(t--){
        cin>>w>>h;
        cin>>x1>>y1>>x2>>y2;
        int dx = x2-x1,dy = y2-y1;
        bool flag = false;
        cin>>W>>H;
        int ans = 1e16;
        if(x1>=W)flag= true,ans = 0;
        else {
            int diff = W-x1;
            if(x2+diff<=w){
                ans = min(ans,diff);
                flag = true;
            }
        }
        if(y1>=H)flag = true,ans =0;
        else {
            int diff = H-y1;
            if(y2+diff<=h){
                ans = min(ans,diff);
                flag = true;
            }
        }
        if(w-x2>=W)flag = true,ans = 0;
        else {
            int diff =W-(w-x2);
            if(x1-diff>=0){
                ans = min(ans,diff);
                flag = true;
            }
        }
        if(h-y2>=H)flag = true,ans =0;
        else{
            int diff = H-(h-y2);
            if(y1-diff>=0){
                ans = min(ans,diff);
                flag = true;
            }
        }
        if(!flag)cout<<-1<<endl;
        else cout<<fixed<<setprecision(10)<<(double)ans<<endl;
    }
    return 0;
}  
