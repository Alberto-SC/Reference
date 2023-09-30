#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<vector<lli>> bags(3);
    bags[0].resize(n1);
    bags[1].resize(n2);
    bags[2].resize(n3);
    vector<lli> s(3);
    for(auto &c:bags[0])cin>>c,s[0]+=c;
    for(auto &c:bags[1])cin>>c,s[1]+=c;
    for(auto &c:bags[2])cin>>c,s[2]+=c;
    sort(bags[0].begin(),bags[0].end());
    sort(bags[1].begin(),bags[1].end());
    sort(bags[2].begin(),bags[2].end());
    lli ans1 = 0;
    lli total = s[0]+s[1]+s[2];
    ans1 = total-(2*min({s[0],s[1],s[2]}));
    lli ans2 = 0;
    sort(bags.begin(),bags.end());
    ans2 = total-(2*(bags[0][0]+bags[1][0]));
    cout<<max(ans1,ans2)<<endl;
    return 0;
}  

