#include <bits/stdc++.h>
using namespace std;
bool inside(int a, int b, int x, int y) { 
    if (x - y - b <= 0 && x - y + b >= 0 && x + y - 2 * a + b <= 0 && x + y - b >= 0) 
        return true; 
  
    return false; 
} 
int main(){
    int d,n,q,a,b;
    cin>>d>>n>>q;
    for(int i = 0;i<q;i++){
        cin>>a>>b;
        inside(d,n,a,b)?cout<<"YES"<<endl:cout<<"NO"<<endl;        
    }
    return 0;
}