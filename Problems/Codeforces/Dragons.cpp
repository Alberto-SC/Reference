#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s,xi,yi;
    cin>>s>>n;
    vector<pair<int,int>> p(n);
    for(int i = 0;i<n;i++)cin>>xi>>yi,p[i] = {xi,yi};
    sort(p.begin(),p.end());
    int i;
    for(i = 0;i<n;i++){
        if(p[i].first<s)s+=p[i].second;
        else break;
    }
    if(i == n)return cout<<"YES"<<endl,0;
    cout<<"NO"<<endl;
    return 0;
}