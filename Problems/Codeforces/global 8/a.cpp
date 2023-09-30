#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,a,b,n;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        int cont = 0;
        bool turn = false;
        if(a<b)swap(a,b);
        while(a<=n && b<=n){
            if(a+b>n){cont++;break;}
            if(turn)
                a+= b;
            else b+=a;
            turn = !turn;
            cont++;
            // cout<<a<<" "<<b<<endl;
        }
        cout<<cont<<endl;
    }
    return 0;
}