#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> A, pair<int,int> B){
    if(A.first == B.first)return A.second>B.second;
    return A.first<B.first;
}
int main(){
    int n,a,b,last = -1;
    cin>>n;
    vector<pair<int,int>> teams;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        v.push_back({a,b});
        last = max(last,a);
    }
    for(int i = 0;i<n;i++){
        if(v[i].second>=last){
            teams.push_back({last,1});
            teams.push_back({v[i].second,-1});
        }
    }
    cout<<teams.size()/2<<endl;
    return 0;
}