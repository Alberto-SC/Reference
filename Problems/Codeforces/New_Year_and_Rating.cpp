#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
const int inf = 1000000007;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> nums(n);
    bool flag = false;
    for(int i = 0;i<n;i++){
        cin>>nums[i].x>>nums[i].y;
        if(nums[i].y == 2)flag = true;
    }
    if(!flag)return cout<<"Infinity"<<endl,0;
    int sum = 0;
    int l = -inf,r = inf;
    for(int i = 0;i<n;i++){
        if(nums[i].y == 1)
            l = max(l,1900-sum);
        else 
            r = min(r,1899-sum);
        sum+=nums[i].x;
    }    
    if(l>r)cout<<"Impossible"<<endl;
    else cout<<r+sum<<endl;
    return 0;
}