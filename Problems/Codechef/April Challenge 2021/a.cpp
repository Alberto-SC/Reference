#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        int y= (n/4)*44;
        if(n%4 ==0)
            y+=16;
        else if(n%4 ==1){
            y+=20;
            if((n/4)>=1)
                y+= 4*3;
        }
        else if(n%4 ==2){
            y+=36;
            if((n/4)>=1)
                y+= 4*2;
        }
        else if(n%4 ==3){
            y+=51;
            if((n/4)>=1)
                y+=4;
        }
        cout<<y<<endl;
    }
    return 0;
}  
