#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){
	int t= 1,n,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        string nc = "1";
        for(int i = 0;i<c-1;i++){
            nc+="0";
        }
        string nb;
        if(b>c)nb = "1";
        for(int i = 0;i<(b-c)-1;i++){
            nb+="0";
        }
        nb+=nc;
        string na;
        if(a>c)na= "1";
        for(int i = 0;i<(a-c)-1;i++){
            na+="0";
        }
        na+=nc;
        int x = stoi(na),y = stoi(nb);
        if(x==y){
            y+=stoi(nc);
        }
        int z = __gcd(x,y);
        string zz = to_string(z);
        if((int)zz.size()!=c){
            y+=stoi(nc);
        }
        z = __gcd(x,y);
        zz = to_string(z);
        cout<<x<<" "<<y<<endl;
        assert((int)zz.size()== c);
    }
    return 0;
}  
