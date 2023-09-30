#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> nums(n);
    for(int i = 0;i<n;i++){
        int c;
        cin>>c;
        nums[i] = {c,i+1};
    }
    if(n == 1)return cout<<"0 0"<<endl,0;
    // else if(n == 2)return abs(nums[0].x-nums[1].x)%2==cout<<"0 0"<<endl,0;
    sort(nums.rbegin(),nums.rend());
    int instability = nums[0].x-nums[n-1].x,aux = k,inst2;
    vector<pair<int,int>> ans;
    while(1 && k){
        nums[0].x--;
        nums[n-1].x++;
        int savei = nums[0].y,savej = nums[n-1].y;
        sort(nums.rbegin(),nums.rend());
        inst2 = nums[0].x-nums[n-1].x;
        if(inst2<=instability){
            instability = inst2;
            ans.push_back({savei,savej});
            k--;
        }
        else break;
    }
    cout<<instability<<" "<<aux-k<<endl;
    for(auto c:ans)cout<<c.x<<" "<<c.y<<endl;
    return 0;
}