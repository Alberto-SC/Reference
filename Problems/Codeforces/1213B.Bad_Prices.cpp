#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        stack<pair<int,int>>s;
        vector<int> g(n,-1);
        for(int i = 0;i<n;i++){
            while(!s.empty() && s.top().first>nums[i]){
                g[s.top().second] = i;
                s.pop();
            }
            s.push({nums[i],i});
        }
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(g[i]!= -1)cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}