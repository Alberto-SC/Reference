#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t ,n,a,b,c,d,e;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(d&1){
            int cont = 0;
            if(a&1)cont++;
            if(b&1)cont++;
            if(c&1)cont++;
            if(cont>=1){
                cont = 0;
                a--,b--,c--;
                if(a>=0 && b>=0&& c>=0){
                    if(a&1)cont++;
                    if(b&1)cont++;
                    if(c&1)cont++;
                }
                else {
                    cout<<"No"<<endl;
                    continue;
                }
                if(cont>1)cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
            }   
            else cout<<"Yes"<<endl;

        }
        else {
            int cont = 0;
            if(a&1)cont++;
            if(b&1)cont++;
            if(c&1)cont++;
            if(cont == 3)cout<<"Yes"<<endl;
            else if(cont == 2)cout<<"NO"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}

