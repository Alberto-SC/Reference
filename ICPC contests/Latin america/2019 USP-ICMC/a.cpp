#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main(){
    int n,ai;
    cin>>n;
    vector<pair<int,int>> nums(n);
    vector<int> ans(n,0);

    for(int i = 0;i<n;i++){
        cin>>ai;
        nums[i] = {ai,i};
    }
    for(int i = 0;i<n;i++)
        ans[i] = min((nums[i].x+i)-i,n-(i+1));
    stack<pair<int,int>> s;
    for(int i = 0;i<n;i++){
        if(!s.empty()){
            while(!s.empty() && s.top().x< nums[i].x){
                ans[s.top().y] =min(ans[s.top().y],i-s.top().y-1); 
                s.pop();
            }
        }
        s.push(nums[i]);
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;

    return 0;
}