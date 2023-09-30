#include <bits/stdc++.h> 
using namespace std;
typedef long long int lli;
#define print(A)for(auto c:A)cout<<c<<" ";
int main(){
    int n;
    cin>>n;
    vector<int> first(n),second(n);
    for(auto &x:first)cin>>x;
    for(auto &x:second)cin>>x;
    int sum1 = accumulate(first.begin(),first.end(),0);
    int sum2 = accumulate(second.begin(),second.end(),0);
    sum2<=sum1? cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}