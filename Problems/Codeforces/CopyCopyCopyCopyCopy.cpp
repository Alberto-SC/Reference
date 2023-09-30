#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        set<int> s;
        for(auto &c:nums)cin>>c,s.insert(c);
        cout<<s.size()<<endl;
    }
    return 0;
}