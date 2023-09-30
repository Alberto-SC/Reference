#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,c1,c2,c3,c4,c5,c6;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>x>>y;
        cin>>c1>>c2>>c3>>c4>>c5>>c6;
        int p;
        if(y== 0 && x>0)p = 6;
        else if(y == 0 && x<0)p =3;
        else if(y>1){
            pair<int,int> t = {x,y};
            pair<int,int> m = {min(x,y),min(x,y)};
            if(t>m){
                if(x<=0) p = 3;
                else p = 2;
            }
            else {
                if(x<=0)p = 5;
                else p = 6;
            }
        } 
        else if(y<0){

        }
        if(p == 1){

        }
        else if(p == 2){

        }
        else if(p == 3){
            
        }
        else if(p == 4){

        }
        else if(p == 5){

        }
        else{

        }
    
    }
    return 0;
}

