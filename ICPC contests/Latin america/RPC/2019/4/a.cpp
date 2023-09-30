#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,x,ans;
    cin>>n>>x;
    vector<int> pr(n);
    for(int i = 0;i<n;i++)
        cin>>pr[i];
    ans = 1;
    sort(pr.begin(),pr.end());
    for(int i = 1;i<n;i++)
        if(pr[i]+pr[i-1]<=x)
            ans = i+1;
    cout<<ans<<endl;
    return 0;
}