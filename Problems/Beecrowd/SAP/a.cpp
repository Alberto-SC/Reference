#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

bool isSquare(int x){
    if((int)sqrt(x)*(int)sqrt(x)== x)return true;
    return false;
}

signed main(){__
    int a,b,c;
    cin>>a>>b>>c;
    if(isSquare((b*b) -(4*a*c)))
        cout<<"Y"<<endl;
    else cout<<"N"<<endl;


}   