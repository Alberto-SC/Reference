#include<bits/stdc++.h>

using namespace std;

int main(){
    double d,s,e;
    cin>>d>>s>>e;
    double prob = 0.0;
    if(d-e<2*s){
        prob = (e+s)/d;
    }else{
        prob = ((d-s)/d )*(s/(d-s-e));
    }
    cout<<setprecision(8)<<prob<<"\n";
    return 0;
}