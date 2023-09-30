#include <bits/stdc++.h>
using namespace std;
typedef long long int lli ;
int main(){
    lli t,n,ans = 0;
    cin>>n;
    vector<lli>M(n);
    vector<lli>A(n);
    for(auto&c:M)cin>>c;
    for(auto&c:A)cin>>c;
    vector<lli> diff(n);
    for(lli i = 0;i<n;i++)
        diff[i] = M[i]-A[i];
    sort(diff.begin(),diff.end());
    lli  i;
    for(i = 0;i<n;i++){
        if(diff[i]>=0)break;
        lli index = lower_bound(diff.begin(),diff.end(),(-1*diff[i])+1)-diff.begin();
        ans+=n-index;
    }
    while(i<n && diff[i]==0){i++;}
    for(lli k= 0;k<n;k++)if(diff[k] == 0)ans+=n-i;
    i = (n-1)-i;
    ans+=(i*(i+1))/2;
    cout<<ans<<endl;
    return 0;
}
// 12
// 4 4 4 4 5 5 5 5 5 6 7 8
// 8 7 6 5 5 5 5 5 4 4 4 4 