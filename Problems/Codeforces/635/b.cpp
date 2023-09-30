#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,x,n,m;
    cin>>t;
    while(t--){
        cin>>x>>n>>m;
        bool flag = false;
        while(n||m){
            if(x>(10*m) && n){
                x/=2;
                x+=10;
                n--;
            }
            else if(x>(10*m) && n == 0){
                x-=10;
                m--;
            }
            else if(x<=(10*m) && m){
                x-=10;
                m--;
            }
            if(x<=0){flag = true;break;}
        }
        	cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}