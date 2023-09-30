#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    int holes[100005];
    int s = 0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>holes[i];
        s += holes[i];
    }
    sort(holes+1,holes+n);
    int cont = 0;
    int f = 0;
    for(int i=n-1;i>=1;i--){
        if(a * holes[0]/s >= b){
        cout<<cont<<endl;
        f = 1;
        break;
        }
        cont++;
        s -= holes[i];
    }
    if(!f)cout<<cont<<endl;
    return 0;
}