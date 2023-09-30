#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    vector<lli> potencias;
    lli pot = 1;
    potencias.push_back(pot);
    while(pot <n){
        pot = pot*3;
        potencias.push_back(pot);
    }
    lli potc = potencias[upper_bound(potencias.begin(),potencias.end(),n)-potencias.begin()];
    cout<<potc<<endl;
    for(auto c:potencias)cout<<c<<" ";

}
