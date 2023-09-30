#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> a;
vector<int> b;
double m;
int n;
bool check(double x){
    double total = m+x;
    for(int i = 0;i<n;i++){
        if(!i){
            double need = total/a[i];  
            x-=need;
            if(isgreater(0,x))return false;
            total-= need;
        }
        else{
            double need = total/b[i];
            x-=need;
            if(isgreater(0,x))return false;
            total-= need;
            need = total/a[i];
            x-=need;
            if(isgreater(0,x))return false;
            total-=need;
        }
    }
    double need = total/b[0];
    total-=need;
    x-=need;
    // cout<<fixed<<setprecision(10);
    // cout<<x<<" "<<total<<endl;
    if(isgreater(x,0))return true;
    return false;
}

int main(){__
	int t= 1;
    while(t--){
        cin>>n>>m;
        a.resize(n);
        b.resize(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        double l = 0,r = 1000000001;
        int cont = 150;
        while(cont--){
            double m = (l+r)/2;
            if(check(m))
                r = m;
            else 
                l = m;
        }
        cout<<fixed<<setprecision(10);
        if(r == 1000000001)cout<<-1<<endl;
        else
            cout<<r<<endl;
    }
    return 0;
}  

