#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";
int main(){
    long long int n,x1,y1,x2,y2,min,ans = 0;
    cin>>n>>x1>>y1>>x2>>y2;
    min = abs(x2-x1)+abs(y2-y1);
    if(min <=n)ans =1;
    else {cout<<0;return 0;}
    if(min == 0)ans-=1;
    ans += (n-min)/2;
    cout<<ans;
    return 0;
}