#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> A, pair<int,int> B){
    if(A.first == B.first)return A.second<B.second;
    return A.first>B.first;
}
int main(){
    int n,need,death;
    int h = 0,ans = 0;
    cin>>n;
    vector<pair<int,int>> sol(n);
    for(int i = 0;i<n;i++){
        cin>>need>>death;
        sol[i] = {need,death};
    }   
    sort(sol.begin(),sol.end(),comp);
    // for(auto c:sol)cout<<c.first<<" "<<c.second<<endl;
    
    for(int i = 0;i<n;i++){   
        if(h<sol[i].first)ans +=sol[i].first-h,h=sol[i].first;
        h-= sol[i].second;
    }
    cout<<ans<<endl;
    return 0;
}

