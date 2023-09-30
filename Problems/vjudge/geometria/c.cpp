#include <bits/stdc++.h>
using namespace std;
#define all(A)A.begin(),A.end()
typedef long long int lli;
bool compy(pair<int,int> A,pair<int,int> B){
    if(A.second == B.second)return A.first<B.first;
    return A.second<B.second;
}
int main(){
    int n,x,y;
    cin>>n;
    vector<pair<int,int>> pairs(n);
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        pairs[i] = {x,y};
    }
    lli ans = 0;
    sort(all(pairs));
    for(int i = 0,j = 0;i<n;i=j){
        while(j<n && pairs[i].first== pairs[j].first)j++;
        int count = j-i;
        ans += 1ll*count*(count-1)/2;
    }
    sort(all(pairs),compy);
    for(int i = 0,j = 0;i<n;i=j){
        while(j<n && pairs[i].second== pairs[j].second)j++;
        int count = j-i;
        ans += 1ll*count*(count-1)/2;
    }
    for(int i = 0,j = 0;i<n;i=j){
        while(j<n && pairs[i].second== pairs[j].second && pairs[i].first == pairs[j].first)j++;
        int count = j-i;
        ans -= 1ll*count*(count-1)/2;
    } 
    cout<<ans<<endl;
    return 0;
}