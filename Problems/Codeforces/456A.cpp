#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,p,q;
    cin>>n;
    vector<pair<int,int>> prices;
    for(int i = 0;i<n;i++){
        cin>>p>>q;
        prices.push_back({p,q});
    }
    sort(prices.begin(),prices.end());
    for(int i = 1;i<n;i++){
        if(prices[i].second<prices[i-1].second)return cout<<"Happy Alex"<<endl,0;
    }
    cout<<"Poor Alex"<<endl;
    return 0;
}