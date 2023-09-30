#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x1,x2,x3,y1,y2,y3;
    cin>>t;
    while(t--){
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        int mn = abs(x1-x2)+abs(y1-y2);
        if(x1==x2 && x1==x3){
            if(y1>=y2 && y3<=y1 && y3>=y2){ 
                mn+=2;
            }
            else if(y1<=y2 && y3>=y1 && y3<=y2){ 
                mn+=2;
            }

        }
        if(y1==y2 && y1==y3){
            if(x1>=x2 && x3<=x1 && x3>=x2){ 
                mn+=2;
            }
            else if(x1<=x2 && x3>=x1 && x3<=x2){ 
                mn+=2;
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}  
