#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> A,pair<int,int> B){
    if(A.second == B.second)return A.first<B.first;
    return A.second<B.second;
}
int main(){
    int n,m,a,b;
    cin>>n;
    vector<pair<int,int>>NN(n);
    for(int i = 0;i<n;i++)cin>>a>>b,NN[i] = {a,b};
    cin>>m;
    vector<pair<int,int>>MM(m);
    for(int i = 0;i<m;i++)cin>>a>>b,MM[i] = {a,b};
    sort(NN.begin(),NN.end(),comp);
    sort(MM.begin(),MM.end());
    int ans1,ans2;
    // cout<<MM[m-1].first<<" "<<NN[0].second<<endl;
    MM[m-1].first-NN[0].second>=0?ans1=MM[m-1].first-NN[0].second:ans1 =0;
    sort(NN.begin(),NN.end());
    sort(MM.begin(),MM.end(),comp);
    NN[n-1].first-MM[0].second>=0?ans2 =NN[n-1].first-MM[0].second:ans2 = 0;
    cout<<max(ans2,ans1)<<endl;
    return 0;
}