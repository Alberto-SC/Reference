#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli a,b;
    cin>>a>>b;
    vector <lli> divs;
    for (lli i = 1;i*i<=a;i++){
        if(a%i == 0)divs.push_back(i);
        if(a%i== 0 && a/i != i)divs.push_back(a/i);
    }
    sort(divs.begin(),divs.end());
    for(auto c:divs)if(c>=b && c%b== 0 )cout<<c<<" ";
    cout<<endl;
    return 0;
}