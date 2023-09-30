#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    vector<int> buck(k,0);
    for(int i = 0;i<n;i++)
        buck[s[i]-'A']++;
    int ans = 500000;
    for(auto c:buck)ans =min(ans,c);
    cout<<ans*k<<endl;
    return 0;
}